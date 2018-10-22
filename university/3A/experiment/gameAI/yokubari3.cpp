/*
ucb1とそのほかのアルゴリズムのプログラムの勝率を比較する
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

#define BLACK 1
#define WHITE 2

#define UCB1 0
#define KLUCB 1
#define YOKUBARI 2

//ばくちにならないように打つプログラム

double komi = 6.5;
const int B_SIZE = 9;         // 碁盤の大きさ
const int WIDTH = B_SIZE + 2; // 枠を含めた横幅
const int BOARD_MAX = WIDTH * WIDTH;
double yokubari_rate_black;
double yokubari_rate_white;
int color;

int board[BOARD_MAX] = {
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};

int dir4[4] = {+1, -1, +WIDTH, -WIDTH}; // 右、左、下、上への移動量

int hama[2];
int kifu[1000];
int ko_z;
int all_playouts = 0;

int get_z(int x, int y)
{
    return (y + 1) * WIDTH + (x + 1); // 0<= x <=8, 0<= y <=8
}
int get81(int z)
{
    if (z == 0)
        return 0;
    int y = z / WIDTH;     // 座標をx*10+yに変換。表示用。
    int x = z - y * WIDTH; // 106 = 9*11 + 7 = (x,y)=(7,9) -> 79
    return x * 10 + y;     // 19路ではx*100+y
}
int flip_color(int col)
{
    return 3 - col; // 石の色を反転させる
}

int check_board[BOARD_MAX]; // 検索済みフラグ用

// ダメと石数を数える再帰関数
// 4方向を調べて、空白だったら+1、自分の石なら再帰で。相手の石、壁ならそのまま。
void count_dame_sub(int tz, int color, int *p_dame, int *p_ishi)
{
    int z, i;

    check_board[tz] = 1; // この位置(石)は検索済み
    (*p_ishi)++;         // 石の数
    for (i = 0; i < 4; i++)
    {
        z = tz + dir4[i]; // 4方向を調べる
        if (check_board[z])
            continue;
        if (board[z] == 0)
        {
            check_board[z] = 1; // この位置(空点)はカウント済みに
            (*p_dame)++;        // ダメの数
        }
        if (board[z] == color)
            count_dame_sub(z, color, p_dame, p_ishi); // 未探索の自分の石
    }
}

// 位置 tz におけるダメの数と石の数を計算。
void count_dame(int tz, int *p_dame, int *p_ishi)
{
    int i;
    *p_dame = *p_ishi = 0;
    for (i = 0; i < BOARD_MAX; i++)
        check_board[i] = 0;
    count_dame_sub(tz, board[tz], p_dame, p_ishi);
}

// 石を消す
void kesu(int tz, int color)
{
    int z, i;

    board[tz] = 0;
    for (i = 0; i < 4; i++)
    {
        z = tz + dir4[i];
        if (board[z] == color)
            kesu(z, color);
    }
}

const int FILL_EYE_ERR = 1;
const int FILL_EYE_OK = 0;

// 石を置く。エラーの時は0以外が返る。playoutではfill_eye_err = 1
int move(int tz, int color, int fill_eye_err)
{
    if (tz == 0)
    {
        ko_z = 0;
        return 0;
    } // パスの場合

    int around[4][3];               // 4方向のダメ数、石数、色
    int un_col = flip_color(color); // 相手の石の色

    // 4方向の石のダメと石数を調べる
    int space = 0;       // 4方向の空白の数
    int kabe = 0;        // 4方向の盤外の数
    int mikata_safe = 0; // ダメ2以上で安全な味方の数
    int take_sum = 0;    // 取れる石の合計
    int ko_kamo = 0;     // コウになるかもしれない場所
    int i;
    for (i = 0; i < 4; i++)
    {
        around[i][0] = around[i][1] = around[i][2] = 0;
        int z = tz + dir4[i];
        int c = board[z]; // 石の色
        if (c == 0)
            space++;
        if (c == 3)
            kabe++;
        if (c == 0 || c == 3)
            continue;
        int dame; // ダメの数
        int ishi; // 石の数
        count_dame(z, &dame, &ishi);
        around[i][0] = dame;
        around[i][1] = ishi;
        around[i][2] = c;
        if (c == un_col && dame == 1)
        {
            take_sum += ishi;
            ko_kamo = z;
        }
        if (c == color && dame >= 2)
            mikata_safe++;
    }

    if (take_sum == 0 && space == 0 && mikata_safe == 0)
        return 1; // 自殺手
    if (tz == ko_z)
        return 2; // コウ
    if (kabe + mikata_safe == 4 && fill_eye_err)
        return 3; // 眼(ルール違反ではない)
    if (board[tz] != 0)
        return 4; // 既に石がある

    for (i = 0; i < 4; i++)
    {
        int d = around[i][0];
        int n = around[i][1];
        int c = around[i][2];
        if (c == un_col && d == 1 && board[tz + dir4[i]])
        { // 石が取れる
            kesu(tz + dir4[i], un_col);
            hama[color - 1] += n;
        }
    }

    board[tz] = color; // 石を置く

    int dame, ishi;
    count_dame(tz, &dame, &ishi);
    if (take_sum == 1 && ishi == 1 && dame == 1)
        ko_z = ko_kamo; // コウになる
    else
        ko_z = 0;
    return 0;
}

void print_board()
{
    int x, y;
    const char *str[3] = {".", "●", "○"};

    printf("     ");
    for (x = 0; x < B_SIZE; x++)
        printf("%d ", x + 1);
    printf("\n");
    for (y = 0; y < B_SIZE; y++)
    {
        printf("%2d: ", y + 1);
        for (x = 0; x < B_SIZE; x++)
        {
            printf("%s", str[board[get_z(x, y)]]);
        }
        printf("\n");
    }
}

// 地を数えて勝ちか負けかを返す
int count_score(int turn_color)
{
    int score = 0;
    int kind[3]; // 盤上に残ってる石数
    kind[0] = kind[1] = kind[2] = 0;
    int x, y, i;
    for (y = 0; y < B_SIZE; y++)
        for (x = 0; x < B_SIZE; x++)
        {
            int z = get_z(x, y);
            int c = board[z];
            kind[c]++;
            if (c != 0)
                continue;
            int mk[4]; // 空点は4方向の石を種類別に数える
            mk[1] = mk[2] = 0;
            for (i = 0; i < 4; i++)
                mk[board[z + dir4[i]]]++;
            if (mk[1] && mk[2] == 0)
                score++; // 同色だけに囲まれていれば地
            if (mk[2] && mk[1] == 0)
                score--;
        }
    score += kind[1] - kind[2];

    double final_score = score - komi;
    int win = 0;
    if (final_score > 0)
        win = 1;
    //  printf("win=%d,score=%d\n",win,score);
    //  win = score;

    if (turn_color == 2)
        win = -win;
    return win;
}

int playout(int turn_color)
{
    all_playouts++;
    int color = turn_color;
    int before_z = 0; // 1手前の手
    int loop;
    int loop_max = B_SIZE * B_SIZE + 200; // 最大でも300手程度まで。3コウ対策
    for (loop = 0; loop < loop_max; loop++)
    {
        // すべての空点を着手候補にする
        int kouho[BOARD_MAX];
        int kouho_num = 0;
        int x, y;
        for (y = 0; y < B_SIZE; y++)
            for (x = 0; x < B_SIZE; x++)
            {
                int z = get_z(x, y);
                if (board[z] != 0)
                    continue;
                kouho[kouho_num] = z;
                kouho_num++;
            }
        int z, r = 0;
        for (;;)
        {
            if (kouho_num == 0)
            {
                z = 0;
            }
            else
            {
                r = rand() % kouho_num; // 乱数で1手選ぶ
                z = kouho[r];
            }
            int err = move(z, color, FILL_EYE_ERR);
            if (err == 0)
                break;
            kouho[r] = kouho[kouho_num - 1]; // エラーなので削除
            kouho_num--;
        }
        if (z == 0 && before_z == 0)
            break; // 連続パス
        before_z = z;
        //		print_board();
        //		printf("loop=%d,z=%d,c=%d,kouho_num=%d,ko_z=%d\n",loop,get81(z),color,kouho_num,get81(ko_z));
        color = flip_color(color);
    }
    return count_score(turn_color);
}

int select_best_move(int color)
{
    int try_num = 30; // playoutを繰り返す回数
    int best_z = 0;
    double best_value = -100;

    int board_copy[BOARD_MAX]; // 現局面を保存
    memcpy(board_copy, board, sizeof(board));
    int ko_z_copy = ko_z;

    // すべての空点を着手候補に
    int x, y;
    for (y = 0; y < B_SIZE; y++)
        for (x = 0; x < B_SIZE; x++)
        {
            int z = get_z(x, y);
            if (board[z] != 0)
                continue;

            int err = move(z, color, FILL_EYE_ERR); // 打ってみる
            if (err != 0)
                continue; // エラー

            int win_sum = 0;
            int i;
            for (i = 0; i < try_num; i++)
            {
                int board_copy[BOARD_MAX];
                memcpy(board_copy, board, sizeof(board));
                int ko_z_copy = ko_z;

                int win = -playout(flip_color(color));
                win_sum += win;
                //			print_board();
                //			printf("win=%d,%d\n",win,win_sum);

                memcpy(board, board_copy, sizeof(board));
                ko_z = ko_z_copy;
            }
            double win_rate = (double)win_sum / try_num;
            //		print_board();
            //		printf("z=%d,win=%5.3f\n",get81(z),win_rate);

            if (win_rate > best_value)
            {
                best_value = win_rate;
                best_z = z;
                //printf("best_z=%d,v=%5.3f,try_num=%d\n", get81(best_z), best_value, try_num);
            }

            memcpy(board, board_copy, sizeof(board)); // 局面を戻す
            ko_z = ko_z_copy;
        }
    return best_z;
}

typedef struct child
{
    int z;       // 手の場所
    int games;   // この手を探索した回数
    double rate; // この手の勝率
    int next;    // この手を打ったあとのノード
} CHILD;

const int CHILD_MAX = B_SIZE * B_SIZE + 1; // +1はPASS用

typedef struct node
{
    int child_num; // 子局面の数
    CHILD child[CHILD_MAX];
    int child_games_sum; // 子局面の回数の合計
} NODE;

const int NODE_MAX = 10000;
NODE node[NODE_MAX];
int node_num = 0;          // 登録ノード数
const int NODE_EMPTY = -1; // 次のノードが存在しない場合
const int ILLEGAL_Z = -1;  // ルール違反の手

void add_child(NODE *pN, int z)
{
    int n = pN->child_num;
    pN->child[n].z = z;
    pN->child[n].games = 0;
    pN->child[n].rate = 0;
    pN->child[n].next = NODE_EMPTY;
    pN->child_num++;
}

// ノードを作成する。作成したノード番号を返す
int create_node()
{
    if (node_num == NODE_MAX)
    {
        printf("node over Err\n");
        exit(0);
    }
    NODE *pN = &node[node_num];
    pN->child_num = 0;
    pN->child_games_sum = 0;

    int x, y;
    for (y = 0; y < B_SIZE; y++)
        for (x = 0; x < B_SIZE; x++)
        {
            int z = get_z(x, y);
            if (board[z] != 0)
                continue;
            add_child(pN, z);
        }
    add_child(pN, 0); // PASSも追加

    node_num++;
    return node_num - 1;
}

// UCBが一番高い手を選ぶ
int select_best_ucb(int node_n, int algo)
{
    NODE *pN = &node[node_n];
    int select = -1;
    double max_ucb = -999;
    int i;
    if (algo == YOKUBARI && color == WHITE && ((rand() % 100) / 100.) <= yokubari_rate_white)
    {
        select = rand() % (pN->child_num);
    }
    else if (algo == YOKUBARI && color == BLACK && ((rand() % 100) / 100.) <= yokubari_rate_black)
    {
        select = rand() % (pN->child_num);
    }
    else
    {
        for (i = 0; i < pN->child_num; i++)
        {
            CHILD *c = &pN->child[i];
            if (c->z == ILLEGAL_Z)
                continue;
            double ucb = 0;
            if (c->games == 0)
            {
                ucb = 10000 + (rand() & 0x7fff); // 未展開
            }
            else
            {
                //const double C = 0.31;
                //ucb1
                if (algo == UCB1 || algo == YOKUBARI)
                {
                    //これは仮の値
                    const double C = 0.31;
                    ucb = c->rate + C * sqrt(log(pN->child_games_sum) / c->games);
                }
                else if (algo == KLUCB)
                {
                    //ucb = c->rate + C * sqrt(log(pN->child_games_sum) / c->games);
                }
            }
            if (ucb > max_ucb)
            {
                max_ucb = ucb;
                select = i;
            }
        }
        if (select == -1)
        {
            printf("Err! select\n");
            exit(0);
        }
    }

    return select;
}

int search_uct(int color, int node_n, int algo)
{
    NODE *pN = &node[node_n];
    CHILD *c = NULL;

    for (;;)
    {
        int select = select_best_ucb(node_n, algo);
        c = &pN->child[select];
        int z = c->z;
        int err = move(z, color, FILL_EYE_ERR);
        if (err == 0)
            break;
        c->z = ILLEGAL_Z; // 別な手を選ぶ
    }

    int win;
    if (c->games <= 0)
    { // 最初の1回目はplayout. <= 10 でノード数を減らせる
        win = -playout(flip_color(color));
    }
    else
    {
        if (c->next == NODE_EMPTY)
            c->next = create_node();
        win = -search_uct(flip_color(color), c->next, algo);
    }

    // 勝率を更新
    c->rate = (c->rate * c->games + win) / (c->games + 1);
    c->games++;            // この手の回数を更新
    pN->child_games_sum++; // 合計回数も更新
    return win;
}

int uct_loop; // uctでplayoutを行う回数

int select_best_uct(int color, int algo)
{
    node_num = 0;
    int next = create_node();

    int i;
    for (i = 0; i < uct_loop; i++)
    {
        int board_copy[BOARD_MAX]; // 局面を保存
        memcpy(board_copy, board, sizeof(board));
        int ko_z_copy = ko_z;

        search_uct(color, next, algo);

        memcpy(board, board_copy, sizeof(board)); // 局面を戻す
        ko_z = ko_z_copy;
    }
    int best_i = -1;
    int max = -999;
    NODE *pN = &node[next];
    for (i = 0; i < pN->child_num; i++)
    {
        CHILD *c = &pN->child[i];
        if (c->games > max)
        {
            best_i = i;
            max = c->games;
        }
        //  printf("%3d:z=%2d,games=%5d,rate=%.4f\n",i,get81(c->z),c->games,c->rate);
    }
    int ret_z = pN->child[best_i].z;
    //printf("z=%2d,rate=%.4f,games=%d,playouts=%d,nodes=%d\n", get81(ret_z), pN->child[best_i].rate, max, all_playouts, node_num);
    return ret_z;
}

// loop回数
int main(int argc, char *argv[])
{
    uct_loop = atoi(argv[1]);
    int max_play = atoi(argv[2]);
    int black_algo = YOKUBARI;
    int white_algo = YOKUBARI;

    int n_games[10][10];
    int n_black_wins[10][10];
    for (int _i = 0; _i < 10; _i++)
    {
        for (int _j = 0; _j < 10; _j++)
        {
            n_games[_i][_j] == 0;
            n_black_wins[_i][_j] = 0;
        }
    }

    for (int _i = 0; _i < 10; _i++)
    {
        for (int _j = 0; _j < 10; _j++)
        {
            n_games[_i][_j] == 0;
            n_black_wins[_i][_j] = 0;
        }
    }
    int n_win = 0;
    for (int _i = 0; _i < 10; _i++)
    {
        for (int _j = 0; _j < 10; _j++)
        {
            yokubari_rate_black = 0.08;
            yokubari_rate_white = 0.;
            for (int _k = 0; _k < max_play; _k++)
            {
                color = 1;     // 現在の手番の色。黒が1で白が2
                int tesuu = 0; // 手数
                srand((unsigned)time(NULL));
                //	srand( 0 );
                //loop:
                // 盤面初期化
                int i, x, y;
                for (i = 0; i < BOARD_MAX; i++)
                    board[i] = 3;
                for (y = 0; y < B_SIZE; y++)
                    for (x = 0; x < B_SIZE; x++)
                        board[get_z(x, y)] = 0;

                //	static int score_sum;
                //	static int loop_count;

                for (;;)
                {
                    clock_t bt = clock();
                    //		uct_loop = all_playouts/3+1;	// playout数を単純モンテカルロに合わせる
                    all_playouts = 0; // playout回数を初期化
//		int z;
//		if ( tesuu & 1 ) z = select_best_uct(color);
//		else             z = select_best_move(color);
#if 0 // 0 でUCT探索
		int z = select_best_move(color);	// 原始モンテカルロ
#else
                    int z;
                    if (color == BLACK)
                    {
                        z = select_best_uct(color, black_algo);
                    }
                    else if (color == WHITE)
                    {
                        z = select_best_uct(color, white_algo);
                    }

                    //int z = select_best_uct(color, white_algo);

#endif
                    int err = move(z, color, FILL_EYE_OK);
                    if (err != 0)
                    {
                        printf("Err!\n");
                        exit(0);
                    }
                    kifu[tesuu] = z;
                    tesuu++;
                    //print_board();
                    //printf("play_z = %d,手数=%d,色=%d,all_playouts=%d\n", get81(z), tesuu, color, all_playouts);
                    double t = (double)(clock() + 1 - bt) / CLOCKS_PER_SEC;
                    //printf("%.1f 秒, %.0f playout/秒\n", t, all_playouts / t);
                    if (z == 0 && tesuu > 1 && kifu[tesuu - 2] == 0)
                    {
                        if (count_score(BLACK))
                            n_win++;
                        break;
                    }
                    if (tesuu > 300)
                    {
                        break; // 3コウでのループ対策
                    }
                    color = flip_color(color);
                }
            }
            //cout << yokubari_rate_black << " " << yokubari_rate_white << endl;
        }
    }

    cout << endl;

    cout << n_win;

    /*
	// 自己対戦のテスト用
	int score = count_score(1);
	score_sum += score;
	loop_count++;
	FILE *fp = fopen("out.txt","a+");
	fprintf(fp,"Last Score=%d,%d,%d,tesuu=%d\n",score,score_sum,loop_count,tesuu);
	fclose(fp);
	printf("Last Score=%d,%d,%d,tesuu=%d\n",score,score_sum,loop_count,tesuu); color = 1; tesuu = 0; goto loop;
*/
    // SGFで棋譜を
    /*
	printf("(;GM[1]SZ[%d]KM[%.1f]\r\n", B_SIZE, komi);
	for (i = 0; i < tesuu; i++)
	{
		int z = kifu[i];
		int y = z / WIDTH;
		int x = z - y * WIDTH;
		const char *sStone[2] = {"B", "W"};
		printf(";%s", sStone[i & 1]);
		if (z == 0)
		{
			printf("[]");
		}
		else
		{
			printf("[%c%c]", x + 'a' - 1, y + 'a' - 1);
		}
		if (((i + 1) % 10) == 0)
			printf("\r\n");
	}
	printf("\r\n)\r\n");

	return 0;
	*/
}
