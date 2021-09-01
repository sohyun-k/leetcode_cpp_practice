#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int output1 = -1, output2 = -1;
        int sum = 0;
        for (int first_idx = 0; first_idx < nums.size() - 1; first_idx++) {
            sum = 0;
            for (int second_idx = first_idx + 1; second_idx < nums.size(); second_idx++) {
                sum = nums.at(first_idx) + nums.at(second_idx);
                if (sum == target) {
                    output1 = first_idx;
                    output2 = second_idx;
                    break;
                }
            }
            if (output1 != -1 && output2 != -1) {
                result.push_back(output1);
                result.push_back(output2);
                break;
            }
        }
        return result;
    }
};