#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int max = 0;
        int left_max = height.at(0);
        int right_max = height.at(height.size() - 1);
        int l_water = 0, r_water = 0, tot_water = 0;
        int tot = 0;
        for (int idx = 0; idx < height.size(); idx++) {
            if (left_max > height.at(idx)) {
                l_water += left_max - height.at(idx);
            }
            else {
                left_max = height.at(idx);
            }
        }
        for (int idx = height.size() - 1; idx >= 0; idx--) {
            if (right_max > height.at(idx)) {
                r_water += right_max - height.at(idx);
            }
            else {
                right_max = height.at(idx);
            }
        }
        for (int idx = 0; idx < height.size(); idx++) {
            tot += height.at(idx);
            if (max < height.at(idx)) {
                max = height.at(idx);
            }
        }
        tot_water = l_water + r_water - max * height.size() + tot;
        return tot_water;
    }
};