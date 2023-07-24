#include<bits/stdc++.h>
using namespace std;
   //day-110
  //MS001;


int wayToProfit(int ind,int k,bool bought,vector<int>&nums,vector<vector<vector<int>>>&dp){
       
        if(ind==nums.size()){
            
            return 0;
        }
        if(k==0) {
          
            return 0;
        }
        if(dp[ind][bought][k]!=-1) return dp[ind][bought][k];
        int profit=0;
        if(bought){
        
            int sell = nums[ind]  + wayToProfit(ind+1,k-1,false,nums,dp);
          
            int notSell = wayToProfit(ind+1,k,true,nums,dp);
            profit=max(sell,notSell);
        }
        else{
           
        
            int buy = wayToProfit(ind+1,k,true,nums,dp) - nums[ind];
           
            int notBuy =wayToProfit(ind+1,k,false,nums,dp);
            
            profit=max(buy,notBuy);
        }
        return dp[ind][bought][k]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       vector< vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(3,-1)));
        int ans =wayToProfit(0,2,false,prices,dp);
        return ans;
    }