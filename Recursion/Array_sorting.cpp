#include <iostream>
using namespace std;

bool isSorted(int arr[], int size) {
    // Base condition
    if (size == 0 || size == 1) {
        return true;
    }

    // Check if the first element is greater than the next element
    if (arr[0] > arr[1]) {
        return false;
    } else {
        // Recursively check the rest of the array
        bool ans = isSorted(arr + 1, size - 1);
        return ans;
    }
}

int main() {
    int size;
    cout << "Enter Size: ";
    cin >> size;

    // Dynamic array allocation
    int *arr = new int[size];
    
    cout << "Enter Array Values: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    if (isSorted(arr, size)) {
        cout << "The array is sorted." << endl;
    } else {
        cout << "The array is not sorted." << endl;
    }

    // Free dynamically allocated memory
    delete[] arr;

    return 0;
}
//most ques