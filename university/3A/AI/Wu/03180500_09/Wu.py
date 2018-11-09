import sympy
import string
import copy
from sympy.abc import *
from sympy.parsing.sympy_parser import parse_expr
from sympy.polys.polytools import pdiv
import argparse


# iなどの1文字のアルファベットは仮定や結論中の式で使われる可能性があるので使わないようにする


class Wu:
    # 仮定
    hyps = []
    # 示したい結論
    conc = 0
    # 従属変数
    dep_vars = []
    # 三角化した式
    tris = []
    # プリントするか否か
    do_print = True
    # latex出力するか
    do_latex = False
    # 補助条件
    subsidaries = 0
    # wuの手続きで用いるremainderのlist
    rems = []

    # 初期化
    # hypsの要素数と従属変数の数は同じでなくてはならない
    def __init__(self, hyps, conc, dep_vars=[], do_print=True, do_latex=False):
        self.hyps = hyps
        self.conc = conc
        self.dep_vars = dep_vars
        self.do_print = do_print
        self.do_latex = do_latex
        if(len(self.hyps) != len(self.dep_vars)):
            for index in range(len(hyps)):
                self.dep_vars.append(sympy.Symbol(string.ascii_letters[index]))

    def triangulation(self):
        # Step1 n=r (ここではlen(tmp_hyps)がnに相当する)
        # hypsが破壊されるのでコピーしておく
        tmp_hyps = copy.copy(self.hyps)
        # 以下sympy.degree では0の次元はマイナス無限なので注意
        while True:
            # Step2 n=0なら終わり
            if(len(tmp_hyps) == 0):
                break
            if(len(tmp_hyps) == 1):
                self.tris.append(tmp_hyps[-1])
                tmp_hyps.pop(-1)
                continue
            # 今注目している変数 x_n
            now_var = self.dep_vars[len(tmp_hyps)-1]
            # Step3 x_nの次数で昇順にソート
            tmp_hyps = sorted(
                tmp_hyps, key=lambda func: sympy.degree(func, now_var))
            # 最高次数が0の時は仕方ないので最後尾の要素をtrisに入れる
            if(sympy.degree(tmp_hyps[-1], now_var) <= 0):
                self.tris.append(tmp_hyps[-1])
                tmp_hyps.pop(-1)
                continue
            # Step4 x_nを含むのが最後尾の要素のみの時
            if(sympy.degree(tmp_hyps[-2], now_var) <= 0):
                self.tris.append(tmp_hyps[-1])
                tmp_hyps.pop(-1)
                continue
            # Step5 f_j = REM(f_j, f_k+1, x_n) (j=k+2...n)
            # ここまでの流れで必ず２つ以上次数が1以上の関数がある
            tmp_index = 0
            # f_jを探す
            for index in range(len(tmp_hyps)):
                if(sympy.degree(tmp_hyps[index], now_var) > 0):
                    tmp_index = index
                    break
            for index in range(tmp_index+1, len(tmp_hyps)):
                tmp_hyps[index] = pdiv(
                    tmp_hyps[index], tmp_hyps[tmp_index], now_var)[1]
        return self.tris

    def make_remainder(self):
        self.rems = []
        self.rems.append(self.conc)
        self.subsidaries = 0
        for index in range(len(self.tris)):
            if(self.tris[index] == 0):
                self.rems.append(self.rems[-1])
            else:
                if self.subsidaries == 0:
                    self.subsidaries = self.tris[index].expand().coeff(
                        self.dep_vars[len(self.tris)-1-index], sympy.degree(self.tris[index], self.dep_vars[len(self.tris)-1-index]))
                else:
                    self.subsidaries *= self.tris[index].expand().coeff(
                        self.dep_vars[len(self.tris)-1-index], sympy.degree(self.tris[index], self.dep_vars[len(self.tris)-1-index]))
                self.rems.append(pdiv(
                    self.rems[-1], self.tris[index],  self.dep_vars[len(self.tris)-1-index])[-1])
        return self.rems

    # 式のlist, functionsを既約にする
    def make_irreducible(self):
        for index1 in range(len(self.tris)):
            for index2 in range(index1+1, len(self.tris)):
                tmp = sympy.simplify(self.tris[index1]/self.tris[index2])
                self.tris[index1] = sympy.numer(tmp)
                self.tris[index2] = sympy.denom(tmp)

    def prove(self):
        print()
        if self.do_print:
            for index in range(len(hyps)):
                if self.do_latex:
                    print("Hyp_{"+str(index+1)+"}"+" = " +
                          str(sympy.latex(hyps[index])))
                else:
                    print("Hyp"+str(index+1)+" = "+str(hyps[index]))
            if self.do_latex:
                print("Conc ="+str(sympy.latex(self.conc)))
            else:
                print("Conc = "+str(self.conc))
        # 三角化を行う
        self.tris = self.triangulation()
        if self.do_print:
            print()
            for index in range(len(self.tris)):
                print_vars = "(" + str(self.dep_vars[0])
                for index_ in range(1, len(self.dep_vars)-index):
                    print_vars = print_vars + \
                        ", " + str(self.dep_vars[index_])
                print_vars = print_vars + ")"
                if self.do_latex:
                    print("Tri"+"_{"+str(index+1)+"}"+print_vars+" = " +
                          str(sympy.latex(self.tris[index])))
                else:
                    print("Tri"+str(index+1)+print_vars +
                          " = "+str(self.tris[index]))
        # remを作る
        self.make_remainder()
        if self.do_print:
            print()
            for index in range(len(self.rems)):
                if self.do_latex:
                    print("Rem_{"+str(index)+"}"+" = " +
                          str(sympy.latex(self.rems[index])))
                else:
                    print("Rem"+str(index)+"=" +
                          str(self.rems[index]))
        if self.do_print:
            if self.do_latex:
                print("Subsidaries = "+str(sympy.latex(self.subsidaries)))
            else:
                print("Subsidaries = "+str(self.subsidaries))

        print()
        if self.rems[-1] == 0:
            print("The conclusion has successfully proved.")
            return True

        print("Try again")
        # tris を既約にして、再度実行(既約に分解して全パターン実行)
        # 教科書によれば全てのパターンを実行する必要がある。
        # ここは関数にすべき気がする
        irreducible_many_tris = [[]]
        are_all_rem_zero = True
        do_calc = False
        for tri in self.tris:
            tuple_factors = sympy.factor_list(tri)[1]
            new_irreducable_many_tris = []
            for tuple_factor in tuple_factors:
                for irreducible_tris in irreducible_many_tris:
                    tmp = copy.copy(irreducible_tris)
                    tmp.append(tuple_factor[0])
                    new_irreducable_many_tris.append(tmp)
            irreducible_many_tris = copy.copy(new_irreducable_many_tris)

        for irreducible_tris in irreducible_many_tris:
            do_calc = True
            self.tris = copy.copy(irreducible_tris)
            if self.do_print:
                print()
                for index in range(len(self.tris)):
                    print_vars = "(" + str(self.dep_vars[0])
                    for index_ in range(1, len(self.dep_vars)-index):
                        print_vars = print_vars + \
                            ", " + str(self.dep_vars[index_])
                    print_vars = print_vars + ")"
                    if self.do_latex:
                        print("Tri"+"_{"+str(index+1)+"}"+print_vars+" = " +
                              str(sympy.latex(self.tris[index])))
                    else:
                        print("Tri"+str(index+1)+print_vars +
                              " = "+str(self.tris[index]))
            self.make_remainder()
            if self.do_print:
                print()
                for index in range(len(self.rems)):
                    if self.do_latex:
                        print("Rem"+str(index)+" = " +
                              str(sympy.latex(self.rems[index])))
                    else:
                        print("Rem"+str(index)+" = " +
                              str(self.rems[index]))
            if(self.rems[-1] != 0):
                are_all_rem_zero = False
            if self.do_print:
                if self.do_latex:
                    print("Subsidaries = "+str(sympy.latex(self.subsidaries)))
                else:
                    print("Subsidaries = "+str(self.subsidaries))

        if do_calc == False:
            print("can't decompose anymore")
        if are_all_rem_zero and do_calc:
            print("The conclusion has proved.")
            return True
        else:
            print("The conclusion has disproved.")
            return False


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("--latex", help="print functions as tex format",
                        action="store_true")
    parser.add_argument(
        "--noprint", help="don't print anything", action="store_true")
    parser.add_argument("--file", help="input file", type=str)
    parser.add_argument(
        "--vars", help="define denpendent vars.\n ex) a,c,b Order is very important.", type=str)
    args = parser.parse_args()

    hyps = []
    conc = f

    if args.file:
        with open(args.file) as f:
            text = f.read().replace(" ", "")
            hyps = text.split()
            for index in range(len(hyps)):
                print(hyps[index])
                hyps[index] = parse_expr(hyps[index])

    else:
        print("Plese input hypotheticals and conclusion.")
        while True:
            input_s = input()
            if(input_s == ""):
                break
            hyps.append(parse_expr(input_s))

    conc = hyps[-1]
    hyps.pop(-1)

    do_print = True
    do_latex = False
    if args.noprint:
        do_print = False
    if args.latex:
        do_latex = True

    dependent_vars = []
    if args.vars:
        args.vars.replace(" ", "")
        dependent_vars = [str(item) for item in args.vars.split(
            ',')]
        for index in range(len(dependent_vars)):
            dependent_vars[index] = parse_expr(dependent_vars[index])

    wu = Wu(hyps, conc, dep_vars=dependent_vars,
            do_print=do_print, do_latex=do_latex)
    wu.prove()
