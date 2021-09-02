#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        vector<int> interval;
        sort(intervals.begin(), intervals.end());
        for (int idx = 0; idx < intervals.size();) {
            int temp_start = intervals.at(idx).at(0);
            int temp_end = intervals.at(idx).at(1);
            if (idx + 1 == intervals.size()) {
                interval.push_back(temp_start);
                interval.push_back(temp_end);
                result.push_back(interval);
                break;
            }
            else {
                for (int search_idx = idx + 1; search_idx < intervals.size(); search_idx++) {
                    if (temp_end >= intervals.at(search_idx).at(0)) {
                        if (temp_end < intervals.at(search_idx).at(1)) {
                            temp_end = intervals.at(search_idx).at(1);
                        }
                    }
                    else {
                        interval.push_back(temp_start);
                        interval.push_back(temp_end);
                        result.push_back(interval);
                        interval.clear();
                        idx = search_idx;
                        break;
                    }
                    if (search_idx + 1 == intervals.size()) {
                        interval.push_back(temp_start);
                        interval.push_back(temp_end);
                        result.push_back(interval);
                        interval.clear();
                        idx = search_idx + 1;
                    }
                }
            }
        }
        return result;
    }
};