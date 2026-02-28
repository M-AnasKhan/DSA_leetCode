#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int votes = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (votes == 0) {
                majority = nums[i];
                votes = 1;
            }
            else if (nums[i] == majority) {
                votes++;
            }
            else {
                votes--;
            }
        }
        return majority;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "Majority Element: " << obj.majorityElement(nums) << endl;
    return 0;
}