#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<bool>> visited;
    vector<bool> temp;
    int cur_num = 2;

    int numIslands(vector<vector<char>>& grid) {
        // set visited size & make false
        for (int row = 0; row < grid.size(); row++) {
            temp.clear();
            for (int col = 0; col < grid.at(row).size(); col++) {
                temp.push_back(false);
            }
            visited.push_back(temp);
        }
        for (int row = 0; row < visited.size(); row++) {
            for (int col = 0; col < visited.at(row).size(); col++) {
                if (visited.at(row).at(col) == false) {
                    visited.at(row).at(col) = true;
                    if (grid.at(row).at(col) == '0') {
                        continue;
                    }
                    else if (grid.at(row).at(col) == '1') {
                        grid.at(row).at(col) = '0' + cur_num;
                        fourWaysSearch(row, col, '0' + cur_num, grid);
                        cur_num++;
                    }
                }
            }
        }
        return cur_num - 2;
    }
    void fourWaysSearch(int row, int col, char cur, vector<vector<char>>& grid) {
        //right side
        int totrow = grid.size();
        int totcol = grid.at(0).size();
        if (totcol > col + 1) {
            if (visited.at(row).at(col + 1) == false && grid.at(row).at(col + 1) == '1') {
                visited.at(row).at(col + 1) = true;
                grid.at(row).at(col + 1) = cur;
                fourWaysSearch(row, col + 1, cur, grid);
            }
        }
        if (totrow > row + 1) {
            if (visited.at(row + 1).at(col) == false && grid.at(row + 1).at(col) == '1') {
                visited.at(row + 1).at(col) = true;
                grid.at(row + 1).at(col) = cur;
                fourWaysSearch(row + 1, col, cur, grid);
            }
        }
        if (col - 1 >= 0) {
            if (visited.at(row).at(col - 1) == false && grid.at(row).at(col - 1) == '1') {
                visited.at(row).at(col - 1) = true;
                grid.at(row).at(col - 1) = cur;
                fourWaysSearch(row, col - 1, cur, grid);
            }
        }
        if (row - 1 >= 0) {
            if (visited.at(row - 1).at(col) == false && grid.at(row - 1).at(col) == '1') {
                visited.at(row - 1).at(col) = true;
                grid.at(row - 1).at(col) = cur;
                fourWaysSearch(row - 1, col, cur, grid);
            }
        }
    }
};