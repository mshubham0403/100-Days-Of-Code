#include<bits/stdc++.h>
using namespace std;
   //day-104
  //MS001;


 int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        string s2 =s;
        reverse(s2.begin(),s2.end());
     
       for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(s[i-1] == s2[j-1]) dp[i][j]=1 +dp[i-1][j-1];
        
        		else  dp[i][j] =max(dp[i-1][j] , dp[i][j-1]);
          
			}
		}
        int ans =dp[n][n];
       
        return dp[n][n];
    }