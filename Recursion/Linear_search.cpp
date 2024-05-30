#include <iostream>
using namespace std;

bool isSorted(int arr[], int size, int key) {
    // Base condition
    if (size == 0) {
        return false;
    }

    
    if (arr[0]==key) {
        return true;
    } else {
        isSorted(arr + 1, size-1, key);
    }
}

int main() {
    int size,key;
    cout << "Enter Size: ";
    cin >> size;
    cout<< "Enetr Key ";
    cin>>key;

    // Dynamic array allocation
    int *arr = new int[size];
    
    cout << "Enter Array Values: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    if (isSorted(arr, size, key)) {
        cout << "Key found" << endl;
    } else {
        cout << "Key not found" << endl;
    }

    // Free dynamically allocated memory
    delete[] arr;

    return 0;
}
//most ques