#include <iostream>
#include <queue>
using namespace std;

class Solution{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < k; i++){
            pq.push(arr[i]);
        }
        
        for(int i = k; i <= r; i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        int ans = pq.top();
        return ans;
    }
};

int main() {
    Solution sol;
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout << "Kth smallest element is " << sol.kthSmallest(arr, 0, n-1, k) << endl;
    return 0;
}
