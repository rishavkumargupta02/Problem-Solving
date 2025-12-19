/*
7. Reverse Integer
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the
signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21
 
Constraints:
-2^31 <= x <= 2^31 - 1
*/

#include <iostream>
#include <vector>
#include <climits>   //INT_MAX and INT_MIN
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0, rem;

        while (x != 0) {
            rem = x % 10;
            x = x / 10;

            // +ve overflow
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && rem > 7))
                return 0;

            // -ve overflow
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && rem < -8))
                return 0;

            rev = rev * 10 + rem;
        }
        return rev;
    }
};

int main() {
    Solution obj;

    int x;
    cout << "Enter an integer: ";
    cin >> x;

    int result = obj.reverse(x);
    cout << "Reversed integer: " << result << endl;

    return 0;
}
