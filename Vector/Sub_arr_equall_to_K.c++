#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>


//1st Brute Force Appraoch o(n^2) =>

// int subArrEquallToK(vector<int> &nums,int n,int k){
//     int count = 0 ;

//     for(int i = 0 ; i < n ; i++){
//         int sum = 0 ;
//         for(int j = i ; j < n ; j++){
//             sum+=nums[j];
//             if(sum==k){
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// int main(){
//     vector<int> nums = {9,4,20,3,10,5};
//     int n = nums.size();
//     int k = 33;

//     cout<<subArrEquallToK(nums,n,k)<<endl;


//     return 0;
// }

// <===========================================================================================>

//2nd Optimized using Hashing + Prefix Sum (O(n)) =>

int subArrEquallToK(vector<int> &nums,int n ,int k){
    vector<int> prefixSum(n,0);
    prefixSum[0] = nums[0];
    for(int i = 1 ; i < n ; i++){
        prefixSum[i] = prefixSum[i-1]+nums[i];
    }

    unordered_map<int,int>m;
    int count = 0 ;
    for(int j = 0 ; j < n ; j++){
        if(prefixSum[j] == k){
            count++;
        }
        int val = prefixSum[j] - k ;

        if(m.find(val) != m.end()){
            count += m[val];
        }
        if(m.find(prefixSum[j]) == m.end()){
            m[prefixSum[j]] = 0 ;
        }
        m[prefixSum[j]]++;
    }
    return count;
}

int main(){
    vector<int> nums = {9,4,0,20,3,10,5};
    int n = nums.size();
    int k = 33;

    cout<<subArrEquallToK(nums,n,k)<<endl;

    return 0;
}
