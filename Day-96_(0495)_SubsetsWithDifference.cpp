#include<bits/stdc++.h>
using namespace std;
   //day-96
  //MS001;


int numWays(int ind,int target,vector<int>&nums,vector<vector<int>>&dp){

    if(ind==-1){
        if(target==0){
            return 1;
        }
        return 0;
    }
   
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }
    int eS1 =numWays(ind-1,target,nums,dp);
    int eS2 =0;
   if(nums[ind]<=target) eS2= numWays(ind-1,target-nums[ind],nums,dp);
    dp[ind][target]=(eS1+eS2);
    return (eS1+eS2);
}
int countPartitions(int n, int d, vector<int> &arr) {
        int totalSum =accumulate(arr.begin(),arr.end(),0);
        int trgt =(totalSum-d);
        if(trgt<0 ||trgt%2!=0) return 0;
        trgt=trgt/2;
        vector<vector<int>>dp(n+1,vector<int>(trgt+1,-1));
        int ans =numWays(n-1,trgt,arr,dp);
        return ans;
}
    int findTargetSumWays(vector<int>& nums,int target) {
        int n=nums.size(),d=target;
        int totalSum =accumulate(nums.begin(),nums.end(),0);
        int trgt =(totalSum-d);
        if(trgt<0 ||trgt%2!=0) return 0;
        trgt=trgt/2;
        vector<vector<int>>dp(n+1,vector<int>(trgt+1,-1));
        int ans =numWays(n-1,trgt,nums,dp);
        return ans;
    }
int main(){


vector<int>nums= {1,2,1,3,23,45,213,4};


int ans = findTargetSumWays(nums,24);

 cout<<ans<<"\n";
return 0;
}
