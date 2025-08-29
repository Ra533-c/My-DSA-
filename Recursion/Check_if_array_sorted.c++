//we are going to check if a array is sorted or not using recursion 
#include <iostream>
using namespace std;

bool isSorted(int arr[],int n){
    if(n==1 || n==0){
        return true;
    }
    return arr[n-1]>=arr[n-2] && isSorted(arr,n-1);
}

int main(){
    int arr[] = {1,2,9,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    bool result = isSorted(arr,n);
    if(result){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }
    return 0;
}

//T.C => O(n)
//S.C => O(n) (Auxiliary Stack Space)