//we are going perform the binary search algorithm using recursion =>

#include <iostream>
using namespace std;
#include <vector>


bool binary_search(vector<int> &nums, int tar,int n,int st,int end){
    if(st<=end){
        int mid = st+(end-st)/2;

        if(nums[mid]==tar){
            return true;
        }
        else if(nums[mid]<=tar){
            return binary_search(nums,tar,n,mid+1,end);
        }else{
            return binary_search(nums,tar,n,st,mid-1);
        }
    }else{
        return false;
    }
};

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    int n = nums.size();
    int tar = -2 ;
    int st = 0 ;
    int end = n-1;
    bool result = binary_search(nums,tar,n,st,end);
    if(result){
        cout<<"element found"<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }
    return 0;
};