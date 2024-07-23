#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        const int MOD = 1337;
        a %= MOD;
        int result = 1;

        for (int i = 0; i < b.size(); i++) {
            result = (powMod(result, 10, MOD) * powMod(a, b[i], MOD)) % MOD;
        }

        return result;
    }

private:
    int powMod(int x, int n, int mod) {
        int result = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                result = (result * x) % mod;
            }
            x = (x * x) % mod;
            n /= 2;
        }
        return result;
    }
};

int main() {
    Solution solution;
    int a = 2;
    vector<int> b = {3};
    cout << "Result: " << solution.superPow(a, b) << endl;

    a = 2;
    b = {1, 0};
    cout << "Result: " << solution.superPow(a, b) << endl;

    a = 1;
    b = {4, 3, 3, 8, 5, 2};
    cout << "Result: " << solution.superPow(a, b) << endl;

    return 0;
}
