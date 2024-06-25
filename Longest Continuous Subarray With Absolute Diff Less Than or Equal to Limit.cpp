#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int sum=0 ;
        int maxsum=0;
        if(n<limit){
            return n;
        }
      for (int i = 0; i < n; i++) {
            int j = i;
            int min = nums[i];
            int max = nums[i];
            while (j < n) {
                if (nums[j] < min) {
                    min = nums[j];
                }
                if (nums[j] > max) {
                    max = nums[j];
                }
                if (max - min > limit) {
                    break;
                }
                j++;
            }
            if (j - i >= maxsum) {
                maxsum = j - i;
            }
        }
        return maxsum;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {8,2,4,7};
    int limit = 4;
    cout << "Longest subarray: " << solution.longestSubarray(nums, limit) << endl;
    
    return 0;
}