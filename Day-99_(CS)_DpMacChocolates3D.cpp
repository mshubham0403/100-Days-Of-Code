#include<bits/stdc++.h>
using namespace std;
   //day-99
  //MS001;


int maxChoclates(int sr,int ac,int bc,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
    if(ac<0||bc<0 || ac>=grid[0].size() || bc>=grid[0].size() ) return -1e9;
    if(sr==(grid.size()-1)){
        int gains;
        if(ac!=bc)  gains =grid[sr][ac]+grid[sr][bc];
        else   gains =grid[sr][ac];
        return gains;
    }
    if(dp[sr][ac][bc]!=-1){
        return dp[sr][ac][bc];
    }
    int gains;
    int maxFutureGains =-1e9;
    if(ac!=bc) gains =grid[sr][ac]+grid[sr][bc];
    else   gains =grid[sr][ac];
    
    for(int diffA=-1;diffA<2;diffA++){
        for(int diffB=-1;diffB<2;diffB++){
            maxFutureGains = max(maxFutureGains,maxChoclates(sr+1,ac-diffA,bc-diffB,grid,dp));
        }
    }
    dp[sr][ac][bc]=gains+maxFutureGains;
    return gains + maxFutureGains;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r+1,vector<vector<int>>(c+1,vector<int>(c+1,-1)));
    int ans = maxChoclates(0,0,c-1,grid,dp);
    return ans;
}
int main(){


vector<vector<int>>grid= {
                                {0,2,5},
                                {1,5,8},
                                {7,1,6},
                                {4,3,8},
                                {4,8,3},
                                {7,2,6},
                                {6,2,8},
                                {4,1,9}
                             
};


int ans = maximumChocolates(9,3,grid);

 cout<<ans<<"\n";
return 0;
}
