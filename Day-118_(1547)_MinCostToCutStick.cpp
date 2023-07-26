#include<bits/stdc++.h>
using namespace std;
   //day-118
  //MS001;

   int  costPortion (int i,int j,vector<int> &cuts,vector<vector<int>>&dp){
        //base case
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        //recurrence
        int costForRange =1e9;
        int right =cuts[j+1];
        int left =  cuts[i-1];  
        
      
        for(int k=i;k<=j;k++){
            int cost = right -left;
            int rightPortion = costPortion(k+1,j,cuts,dp);
            int leftPortion =costPortion(i,k-1,cuts,dp);
            cost=cost+rightPortion+leftPortion;
            if(cost<costForRange){
                costForRange =cost;
            }
        }
        return dp[i][j]=costForRange;
    }
  int minCost(int n, vector<int>& cuts) {
         cuts.push_back(n);
         cuts.insert(cuts.begin(),0);
         sort(cuts.begin(),cuts.end());
         int numCuts=cuts.size()-2;
      vector<vector<int>>dp(numCuts+1,vector<int>(numCuts+1,-1));
      int ans =costPortion(1,numCuts,cuts,dp);
      return ans;
  }