#include<bits/stdc++.h>
using namespace std;
   //day-102
  //MS001;


string findLCS(int n, int m,string &s1, string &s2){
	 vector<vector<int>>dp(n+1,vector<int>(m+1,0));
 
        int p1 =n;
        int p2 =m;
		
		for(int i=1;i<=p1;i++){
			for(int j=1;j<=p2;j++){
				if(s1[i-1] ==s2[j-1]) dp[i][j]=1 +dp[i-1][j-1];
        
        		else  dp[i][j] =max(dp[i-1][j] , dp[i][j-1]);
          
			}
		}
        int len =dp[n][m];
   
	 string ans ="";
   int i=n,j=m;
   while(i>0 && j>0){
     if(s1[i-1]==s2[j-1]){
       ans=s1[i-1]+ans;
     
       i--;j--;
     }
     else if(dp[i-1][j]>dp[i][j-1]){
       i--;
     }
     else{
       j--;
     }
   }
	return ans;	
}
  