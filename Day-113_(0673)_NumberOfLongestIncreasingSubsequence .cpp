#include<bits/stdc++.h>
using namespace std;
   //day-113
  //MS001;

int findNumberOfLIS(vector<int>& nums) {
    int n=nums.size();
      vector<int>dp(n+1,1);
      vector<int> count(n+1,1);
      int maxDP=1;
      for(int i =0;i<n;i++){
          for(int j=0;j<i;j++){
              if(nums[j]<nums[i]){
                  if(dp[i]<dp[j]+1){
                      dp[i]=dp[j]+1;
                      count[i]=count[j];
                      
                    }
                 
                 else if(dp[i]==dp[j]+1){
                    count[i]+=count[j];}
              }
              
          }
          maxDP =max(maxDP,dp[i]);
      }
              
      int numWays=0;
      for(int i=0;i<n;i++){
          if(dp[i]==maxDP){
              numWays+=count[i];
          }
      }
      return numWays;
  }