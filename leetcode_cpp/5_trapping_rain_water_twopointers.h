#include <vector>
using namespace std;
 
class Solution {
public:
    int trap(vector<int>& height) {
        int left_idx = 0;
        int right_idx = height.size() - 1;
        int left_height = height.at(0), right_height = height.at(height.size()-1);
        int water = 0;
        while (left_idx != right_idx) {
            if (left_height <= right_height) {
                left_idx++;
                if (left_height > height.at(left_idx)) {
                    water += left_height - height.at(left_idx);
                }
                else if (left_height < height.at(left_idx)) {
                    left_height = height.at(left_idx);
                }
            }
            else {
                right_idx--;
                if (right_height > height.at(right_idx)) {
                    water += right_height - height.at(right_idx);
                }
                else if (right_height < height.at(right_idx)) {
                    right_height = height.at(right_idx);
                }
            }
        }
        return water;
    }
};