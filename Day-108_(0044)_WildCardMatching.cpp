#include<bits/stdc++.h>
using namespace std;
   //day-108
  //MS001;


bool canMatch(int p1,int p2,string &s1,string &s2,vector<vector<int>>&dp){
if(p1<0 && p2<0){
    return true;
}
if(p1<0 && p2>-1){
    for(int i=p2;i>-1;i--){
        if(s2[i]!='*') return false;
    }
    return true;
}
if(p1>-1 && p2<0){
    return false;
}
if(dp[p1][p2]!=-1) return dp[p1][p2];

if(s1[p1]==s2[p2] || s2[p2]=='?'){
    return dp[p1][p2] = canMatch(p1-1,p2-1,s1,s2,dp);
}
if(s2[p2]=='*'){
 bool eat = canMatch(p1-1,p2,s1,s2,dp);
 bool eaten =canMatch(p1,p2-1,s1,s2,dp);
 return dp[p1][p2] =( eat||eaten);
}
if(s1[p1]!=s2[p2]){
    return dp[p1][p2]= false;
}
return false;
}

    bool isMatch(string s, string p) {
    int n=s.length(),m=p.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    bool ans = canMatch(n,m,s,p,dp);
    return ans;    
    }