#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth largest element and return using this function
    int kthLargest(int arr[], int l, int r, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        // Add first k elements to the min heap
        for (int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }

        // Process the remaining elements of the array
        for (int i = k; i <= r; i++) {
            if (arr[i] > pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        return pq.top();
    }
};

int main() {
    Solution sol;
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << "Kth largest element is " << sol.kthLargest(arr, 0, n - 1, k) << endl;
    return 0;
}
