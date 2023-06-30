#include<bits/stdc++.h>
using namespace std;

  void reverse(vector<int>&nums,int l,int r){
        while(l<=r){
            swap(nums[l],nums[r]);
            l++;r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(k==0){
            return ;
        }
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-k-1);
        reverse(nums,0,n-1);
        
       
    }
int main(){
vector<int>nums={1,2,4,5,3,7,8,5,1,2,11,2};

 rotate(nums,5);
for(auto &x:nums){
  
        cout<<x<<" ";
    }
cout<<endl;


return 0;
}
