#pragma once
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> dir = { {0,1}, {-1,0},{0,-1},{1,0} };
        int cur_dir_idx = 0; // Left +1, right -1
        vector<int> cur_pos = { 0,0 };
        bool result = false;

        // 1time
        for (int repeat = 0; repeat < 4; repeat++) {
            for (int idx = 0; idx < instructions.size(); idx++) {
                char cur_letter = instructions[idx];
                if (cur_letter == 'G') {
                    cur_pos.at(0) += dir.at(cur_dir_idx).at(0);
                    cur_pos.at(1) += dir.at(cur_dir_idx).at(1);
                }
                else if (cur_letter == 'L') {
                    cur_dir_idx += 1;
                    if (cur_dir_idx > 3) {
                        cur_dir_idx = 0;
                    }
                }
                else if (cur_letter == 'R') {
                    cur_dir_idx -= 1;
                    if (cur_dir_idx < 0) {
                        cur_dir_idx = 3;
                    }
                }
            }
            if (cur_pos.at(0) == 0 && cur_pos.at(1) == 0 && cur_dir_idx == 0) {
                result = true;
                break;
            }
        }
        return result;
    }
};