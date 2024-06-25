#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;

        int oddCount = 0;
        int result = 0;

        for (int num : nums) {
            if (num % 2 == 1) {
                oddCount++;
            }
            if (prefixCount.find(oddCount - k) != prefixCount.end()) {
                result += prefixCount[oddCount - k];
            }
            prefixCount[oddCount]++;
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << "Number of nice subarrays: " << solution.numberOfSubarrays(nums, k) << endl;
    
    return 0;
}
