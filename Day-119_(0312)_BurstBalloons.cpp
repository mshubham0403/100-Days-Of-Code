#include<bits/stdc++.h>
using namespace std;
   //day-119
  //MS001;

     int burstRange(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        // recurrence
        int maxCoins =-1e9;
        for(int k=i;k<=j;k++){
            int coins =nums[i-1]*nums[k]*nums[j+1];
            int left =burstRange(i,k-1,nums,dp);
            int right = burstRange(k+1,j,nums,dp);
            int total=coins+left+right;
            if(total>maxCoins){
                maxCoins=total;
            }
        }
        return dp[i][j]=maxCoins;
        
    }
    
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n =nums.size();
        vector<vector<int>>dp(n-1,vector<int>(n-1,-1));
        
        int ans =burstRange(1,n-2,nums,dp);
        return ans;
    }