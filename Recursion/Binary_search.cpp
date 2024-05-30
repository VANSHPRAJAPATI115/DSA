#include <iostream>
using namespace std;

bool Search(int arr[], int s, int e, int key) {
    // Base condition
    if (s > e) {
        return false;
    }
    
    int mid = s + (e - s) / 2;

    if (arr[mid] == key) {
        return true;
    }

    if (arr[mid] < key) {
        return Search(arr, mid + 1, e, key);
    } else {
        return Search(arr, s, mid - 1, key);
    }
}

int main() {
    int size, key;

    cout << "Enter size of array: ";
    cin >> size;

    // Dynamic array allocation
    int *arr = new int[size];
    
    cout << "Enter Array Values: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter Key: ";
    cin >> key;

    int s = 0;
    int e = size - 1;

    if (Search(arr, s, e, key)) {
        cout << "Key found" << endl;
    } else {
        cout << "Key not found" << endl;
    }

    // Free dynamically allocated memory
    delete[] arr;

    return 0;
}
