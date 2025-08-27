#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// <===============================================>
//1st Approach Brute Force =>
// vector<int> findTriplet(int arr[] , vector<int> &ans , int n){
//     for(int i = 0 ; i < n ; i++){
//         for(int j = i+1 ; j < n ; j++){
//             for(int k = j+1 ; k < n ; k++){
//                 if(arr[i]+arr[j]+arr[k] == 0) {
//                     ans.push_back(arr[i]);
//                     ans.push_back(arr[j]);
//                     ans.push_back(arr[k]);
//                 }
//             }
//         }
//     }
//     ans.erase(unique(ans.begin(), ans.end()), ans.end());
//     return ans;
// }

// int main() {
//     int nums[] = {-1, 0, 1, 2, -1, -4};
//     int n = sizeof(nums) / sizeof(nums[0]);
//     vector<int> ans;
//     findTriplet(nums, ans, n);

//     cout << "the triplet is : ";
//     for (int val : ans) {
//         cout << val << " ";
//     }
//     return 0;
// }

// <========================================================================>
//2nd approach Brute Force =>

// int main(){
//     int nums[] = {-1, 0, 1, 2, -1, -4};
//     int n = sizeof(nums) / sizeof(nums[0]) ;

//     vector<vector<int>> ans;
//     set<vector<int>> s;

//     for(int i = 0; i < n; i++) {
//         for(int j = i + 1; j < n; j++) {
//             for(int k = j + 1; k < n; k++) {
//                 if(nums[i] + nums[j] + nums[k] == 0) {
//                     vector<int>trip = {nums[i],nums[j],nums[k]};
//                     sort(trip.begin(),trip.end());
//                     if(s.find(trip) == s.end()){
//                         s.insert(trip);
//                         ans.push_back(trip);
//                     }
//                 }
//             }
//         }
//     }

    


//     // Print the triplets
//     cout << "The triplets are: " << endl;
//     for(const auto& triplet : ans) {
//         cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
//     }

//     return 0;
// }


// <========================================================================>
//2ND Approach Optimized using (Hashinn)  =>

vector<vector<int>> uniqueTriplets(vector<int> &nums,int n){
    set<vector<int>> uniqueTrip;

    //a+b+c = (0) 
    //b+c = -a(tar) => c = tar-b;

    for(int i = 0 ; i < n ; i ++){
        set<int> s;
        int tar = - nums[i];
        for(int j = i + 1 ; j < n ; j++){
            int third  = tar - nums[j];

            if (s.find(third) != s.end()){
                vector<int> trip = {nums[i],nums[j],third};
                sort(trip.begin(),trip.end());
                uniqueTrip.insert(trip);
            }
            s.insert(nums[j]);
        }
    }
    return vector<vector<int>>(uniqueTrip.begin(),uniqueTrip.end());
}

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int n = nums.size();

    vector<vector<int>> result = uniqueTriplets(nums , n);
    cout<<"The Unique Triplets are : "<<endl;
    for(const auto& trip:result){
        cout<<"[";
        for(int val : trip){
            cout<<val<<" ";
        }
        cout<<"]"<<endl;
    }

    return 0;
}