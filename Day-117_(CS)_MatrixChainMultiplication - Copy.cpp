#include<bits/stdc++.h>
using namespace std;
   //day-117
  //MS001;

 int minOps(int strt,int end,int *a,vector<vector<int>>&dp){
    if(strt==end)return 0;
    if(dp[strt][end]!=-1) return dp[strt][end];
    long minOpsForRange=1e9;
    for(int k=strt;k<end;k++){
        
        long ops =a[strt-1]*a[k]*a[end];
        long left =minOps(strt,k,a,dp);
        long right =minOps(k+1,end,a,dp);
        long total =ops+left+right;
        if (minOpsForRange > total) {
          minOpsForRange = total;
        }
    }
    return dp[strt][end]=minOpsForRange;
}


int matrixChainMultiplication(int* arr, int n) {
   vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans = minOps(1,n,arr,dp);
         return ans;
    
}