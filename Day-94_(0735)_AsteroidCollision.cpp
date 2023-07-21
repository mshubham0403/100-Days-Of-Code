#include<bits/stdc++.h>
using namespace std;
   //day-95
  //MS001;


  int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
        //base case
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int j=1;j<=amount;j++){
           if(j%coins[0]==0) dp[0][j]=j/coins[0];
           else dp[0][j]=1e9;
        }
        
        // filling dp
        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
              int notTake =dp[i-1][j];
              int take =1e9;
              if(coins[i]<=j){
                    take = 1+dp[i][j-coins[i]];
               }
              dp[i][j]=min(take,notTake);
            }
        }
        
        int ans =dp[n-1][amount];
        if(ans>=1e9) return -1;
        return ans;
    }
int main(){


vector<int>coins= {2,1,3,43,12,18};
int ans = coinChange(coins,2123);

 cout<<ans<<"\n";
return 0;
}
