#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Using a min-heap priority queue to store the ropes lengths.
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq(arr, arr + n);

        long long cost = 0;

        // Continue combining the two smallest ropes until only one rope remains.
        while (pq.size() > 1) {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long sum = a + b;
            cost += sum;
            pq.push(sum);
        }

        return cost;
    }
};

int main() {
    Solution solution;
    long long arr[] = {4, 3, 2, 6};
    long long n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Minimum cost to connect ropes: " << solution.minCost(arr, n) << std::endl;
    return 0;
}
