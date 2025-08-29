//1.We are going to calculate the factorial of n num using the recusrion 
// #include <iostream>
// using namespace std;

// int fact(int n){
//     if(n == 1){
//         return n; 
//     }

//     int prevNum = fact(n-1);

//     return n*prevNum;
// }

// int main(){
//     cout<<fact(333)<<endl;
//     return 0;
// }


// <===========================================================================>

//2. Sum of n Nums using recursion 

#include <iostream>
using namespace std;

int sum(int n){
    if(n==1){
        return 1;
    }
    int prevNum = sum(n-1);
    return n+prevNum;
}

int main(){
    cout<<sum(4);
    return 0;
}
