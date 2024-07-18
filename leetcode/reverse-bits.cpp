#include <iostream>
#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            ans <<= 1;
            ans |= (n & 1);
            n >>= 1;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    uint32_t n = 43261596; // Example input
    uint32_t result = solution.reverseBits(n);
    
    std::cout << "Reversed bits: " << result << std::endl;
    return 0;
}
