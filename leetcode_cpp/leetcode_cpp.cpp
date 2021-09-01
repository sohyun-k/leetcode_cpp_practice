// leetcode_cpp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "1_twosum_sol.h"

int main()
{
    vector<int> num;
    num.push_back(2);
    num.push_back(7);
    num.push_back(11);
    num.push_back(15);
    int target = 9;
    Solution sol = Solution();
    vector<int> result = sol.twoSum(num, target);

    cout << result.at(0) << " " << result.at(1);
}
