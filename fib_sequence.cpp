#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n value :";
    cin>>n;
    int num=0;
    int num1=1;

    for(int i=1; i<n-1; i++){
        int temp=num1;
     num1=num+num1;
        num=temp;
        
        
    }
    cout<<num1;
    
    return 0;
}

//using recursion and run only platform
int fib(int n){
    if(n==0)
    return 0;
     
     if(n==1)
     return 1;

     int ans = fib(n-1)+fib(n-2);
     return ans;
}


//call with function

// Function to calculate the Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    std::cout << "Enter the position of the Fibonacci sequence you want to find: ";
    std::cin >> n;

    int result = fibonacci(n);
    std::cout << "Fibonacci number at position " << n << " is " << result << std::endl;

    return 0;
}
