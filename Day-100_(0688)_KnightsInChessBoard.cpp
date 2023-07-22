#include<bits/stdc++.h>
using namespace std;
   //day-99
  //MS001;


double waysInOfBoard(int k,int r,int c,int n,double ret,vector<vector<vector<double>>>&dp){
    if(r<0||c<0 || r>=n || c>=n ) return 0;
    
    if(k==0){
       if(r<0||c<0 || r>=n || c>=n ) return 0;
        return ret;
    }
    if(dp[k][r][c]!=-1) return dp[k][r][c];
    
    double waysIn =0;
    
    for(int diffA=-2;diffA<3;diffA++){
        for(int diffB=-2;diffB<3;diffB++){
            if(diffA==diffB || diffA==0 || diffB==0 ||abs(diffB)==abs(diffA)) continue;
            waysIn = waysIn + waysInOfBoard(k-1,r-diffA,c-diffB,n,ret,dp);
        }
    }
    dp[k][r][c]=waysIn;
    return waysIn;
}
double  knightProbability(int n, int k, int row,int col) {
    vector<vector<vector<double>>>dp(k+1,vector<vector<double>>(n+1,vector<double>(n+1,-1)));
  
    double ret =1;
    for(int i=0;i<k;i++){
        ret =ret*(1.00/8.00);
    }
    double inMoves = waysInOfBoard(k,row,col,n,ret,dp);
    
  
    return inMoves;
}
int main(){

double ans = knightProbability(25,89,6,8);

 cout<<ans<<"\n";
return 0;
}
