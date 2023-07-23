#include<bits/stdc++.h>
using namespace std;
   //day-103
  //MS001;


int lcs(string &str1, string &str2){
    int n =str1.length(),m=str2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int maxL =-1e9;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
          if (str1[i - 1] == str2[j - 1]) {
            maxL = max(dp[i][j] = 1 + dp[i - 1][j - 1], maxL);
          } else dp[i][j] = 0;
        }
    }
    return maxL;

}
  