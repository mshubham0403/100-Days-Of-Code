#include<bits/stdc++.h>
using namespace std;
   //day-106
  //MS001;


int findWays(int p1,int p2,string &s1,string &s2,vector<vector<int>>&dp){
        if(p1==-1){
            if(p2!=-1){
                return 0;
            }
            else{
                return 1;
            }
        }
        if(p2==-1){
            return 1;
        }
        if(dp[p1][p2]!=-1){
            return dp[p1][p2];
        }
        int notTake;
        int take = notTake=0;
        if(s1[p1]==s2[p2]){
            notTake =findWays(p1-1,p2,s1,s2,dp);
            take =findWays(p1-1,p2-1,s1,s2,dp);
        }
        else{
            notTake = findWays(p1-1,p2,s1,s2,dp);
        }
        return dp[p1][p2]=take+notTake;
    }
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans =findWays(n,m,s,t,dp);
        return ans;
    }
  