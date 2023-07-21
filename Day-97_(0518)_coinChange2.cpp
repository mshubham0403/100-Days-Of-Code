#include<bits/stdc++.h>
using namespace std;
   //day-97
  //MS001;


int allWays(int ind ,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(ind==0){
            if(target%nums[0]==0) return 1;
            return 0;
        }
        if(target==0) return 1;
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int nt =allWays(ind-1,target,nums,dp);
        int pt =0;
        if(nums[ind]<=target) pt = allWays(ind,target-nums[ind],nums,dp);
        dp[ind][target] =nt+pt;
        return nt+pt;
    }
    int change2(int amount, vector<int>& coins) {
        int n =coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        
        int ans =allWays(n-1,amount,coins,dp);
        return ans;
    }
int main(){


vector<int>nums= {1,2,3,5,7,12,9,15,10};


int ans = change2(24,nums);

 cout<<ans<<"\n";
return 0;
}
