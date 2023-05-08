#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

   long numSubseq(vector<int>& nums, int target) {
    int  mod = 1'000'000'007;
    const int n = nums.size();
    long ans = 0;
    long long tmp=0;
    int l,p=0,r=n-1;
  vector<int> pows(n, 1);  

    for (int i = 1; i < n; i++){
      pows[i] = (pows[i - 1] * 2) % mod;
      }

    sort(nums.begin(), nums.end());
    while(p<=r){
        if(!(nums[p]+nums[r]<=target)){
           r--;  } 
    else{
     
        
          ans=(ans+pows[r-p]);
          ans=ans%mod;
          p++;
    
    }
    }
    
   return ans;
  }
int main(){
vector<int>nums={2,1,3,4,5,8,7,9,6,10,13,12,11,14};

int ans = numSubseq(nums,5);
cout<<ans<<endl;

return 0;
}