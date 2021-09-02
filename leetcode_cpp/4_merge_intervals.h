#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        vector<int> interval;
        for (int first_idx = 0; first_idx < intervals.size();) {
            interval.push_back(intervals.at(first_idx).at(0));
            int temp_end = intervals.at(first_idx).at(1);
            for (int second_idx = first_idx + 1; second_idx < intervals.size(); second_idx++) {
                if (temp_end < intervals.at(second_idx).at(0)) {
                    interval.push_back(intervals.at(second_idx - 1).at(1));
                    result.push_back(interval);
                    interval.clear();
                    first_idx = second_idx;
                    if (first_idx == intervals.size() - 1) {
                        interval.push_back(intervals.at(first_idx).at(0));
                        interval.push_back(intervals.at(first_idx).at(1));
                        result.push_back(interval);
                        first_idx++;
                    }
                    break;
                }
                else {
                    continue;
                }
            }
        }
        return result;
    }
};