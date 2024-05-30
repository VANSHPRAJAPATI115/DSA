#include <iostream>
using namespace std;

int sum(int arr[], int size) {
    // Base condition
    if (size == 0) {
        return 0;
    }
    int remaining = sum(arr+1,size-1);
    return arr[0]+remaining;

    
}

int main() {
    int size,key;
    cout << "Enter Size: ";
    cin >> size;

    // Dynamic array allocation
    int *arr = new int[size];
    
    cout << "Enter Array Values: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout<<sum(arr,size);

    // Free dynamically allocated memory
    delete[] arr;

    return 0;
}
//most ques