#pragma once
#include <vector>
#include <map>
using namespace std;

// using map

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> maps; // <key value, idx>
        for (int cur_idx = 0; cur_idx < nums.size(); cur_idx++) {
            int cur_num = nums.at(cur_idx);
            int desired_num = target - cur_num;
            if (maps.find(desired_num) == maps.end()) {
                maps.insert(pair<int, int>(cur_num, cur_idx));
                continue;
            }
            else {
                result.push_back(cur_idx);
                result.push_back(maps.find(desired_num)->second);
                break;
            }
        }
        return result;
    }
};