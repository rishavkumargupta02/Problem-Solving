#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        vector<int> pre(n);
        vector<int> suff(n);

        // Prefix array
        pre[0] = 1;
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] * nums[i - 1];
        }

        // Suffix array
        suff[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] * nums[i + 1];
        }

        // Final answer
        for (int i = 0; i < n; i++) {
            answer[i] = pre[i] * suff[i];
        }

        return answer;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = sol.productExceptSelf(nums);

    cout << "Output: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
