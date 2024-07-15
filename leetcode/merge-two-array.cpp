#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    vector<int> nums1 = {1, 3, 5, 7};
    vector<int> nums2 = {2, 4, 6, 8};
    vector<int> ans;

    for (auto i : nums1)
        ans.push_back(i);

    for (auto i : nums2)
        ans.push_back(i);

    sort(ans.begin(), ans.end());

    for (auto i : ans)
        cout << i << " ";

    return 0;
}
