#include<bits/stdc++.h>
using namespace std;
   //day-99
  //MS001;


int findLcs(int p1,int p2,string &t1,string &t2,vector<vector<int>>&dp){
        if(p1<0 || p2<0){
            return 0;
        }
        if(dp[p1][p2]!=-1){
            return dp[p1][p2];
        }
        if(t1[p1] == t2[p2]){
            return 1 + findLcs(p1-1,p2-1,t1,t2,dp);
        }
        else{
            dp[p1][p2] =max(findLcs(p1-1,p2,t1,t2,dp) , findLcs(p1,p2-1,t1,t2,dp) );
            return dp[p1][p2];
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1,-1));
        int p1 =text1.length()-1;
        int p2 =text2.length()-1;
        int ans = findLcs(p1,p2,text1,text2,dp);
        return ans ;
    }
