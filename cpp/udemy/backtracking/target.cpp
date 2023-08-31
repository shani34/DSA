#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

    int dp(vector<int>& nums, int index, int currentSum, int target) {
        // Base case: If all elements are processed, check if the sum matches the target
        if (index == nums.size()) {
            if (currentSum == target) {
                return 1;
            }
            return 0;
        }

        // Check if the result is already calculated

        // Calculate the result by considering both '+' and '-' symbols
        int waysWithPlus = dp(nums, index + 1, currentSum + nums[index], target);
        int waysWithMinus = dp(nums, index + 1, currentSum - nums[index], target);

        // Store the result in the memo dictionary and return it
         return waysWithPlus + waysWithMinus;
    }
int main() {
    // Solution solution;
    vector<int> nums ;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    int target ;
    cin>>target;
    int output =dp(nums,0,0,target);
    cout << output << endl;  // Output should be 5
    return 0;
}
