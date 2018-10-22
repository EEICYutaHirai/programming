#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> numbers{1, 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 6, 6, 6};
    std::sort(numbers.begin(), numbers.end());
    // 3より小さい要素の数
    int lessThan3 = std::lower_bound(numbers.begin(), numbers.end(), 3) - numbers.begin();
    std::cout << lessThan3 << std::endl; // 6

    // 3以下の要素の数
    int equalOrLessThan3 = std::upper_bound(numbers.begin(), numbers.end(), 3) - numbers.begin();
    std::cout << equalOrLessThan3 << std::endl; // 9
}