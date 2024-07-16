#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int p = 0;

        for (int i = 1; i <= n; i++) {
            p ^= i;
        }

        for (auto a : nums) {
            p ^= a;
        }

        return p;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 0, 1};
    int result = solution.missingNumber(nums);
    cout << "The missing number is: " << result << endl;
    return 0;
}
