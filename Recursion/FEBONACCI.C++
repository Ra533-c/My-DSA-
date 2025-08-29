//we are calcutalting the fibonacci num using the recursion 
#include <iostream>
using namespace std;

int fibo(int n){
    if(n==0 || n ==1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}

int main(){
    cout<<fibo(7)<<endl;
    return 0;
}

//Time Complexity => O(2^n)
//Space Complexity => O(n) (Auxiliary Stack Space)
