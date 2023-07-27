#include<bits/stdc++.h>
# define ll long long
using namespace std;
   //day-120
  //MS001;

  
long long getWays(int i,int j,int need ,string &exp,vector<vector<vector<ll>>>&dp){
        int mod =1000000007;
        if(i>j) return 0;
        if(i==j) {
            if(need){
                return exp[i]=='T';
            }
            else{
                return exp[i]=='F';
            }
        }
        if(dp[i][j][need]!=-1) return dp[i][j][need];
        
        //recurrence
        long long kWays=0;
        for(int k=i+1;k<j;k+=2){
            ll lt =(getWays(i,k-1,1,exp,dp));
            ll lf =(getWays(i,k-1,0,exp,dp));
            ll rt =(getWays(k+1,j,1,exp,dp));
            ll rf =(getWays(k+1,j,0,exp,dp));
           
            if(exp[k]=='|'){
                    if (need) {
                        kWays += ((lt *rt)%mod) + ((lt*rf)%mod);
                        kWays += (lf * rt)%mod;
                    }
                    else{
                        kWays += (lf * rf)%mod;
                    }
                }
                
            else if(exp[k]=='^'){
                if (need) {
                    kWays += (lt * rf)%mod;
                    kWays += (lf * rt)%mod;
                    }
                else{
                    kWays += (lf * rf)%mod;
                    kWays += (lt * rt)%mod;
                    }
            }
            else if(exp[k]=='&'){
               if (need) {
                     kWays += (lt * rt)%mod;
                }
                else{
                     kWays += (lt * rf)%mod;
                     kWays += ( (lf *rt)%mod ) + ( (lf*rf)%mod);
                }
             }
       
        }
        ll ans =kWays%mod;
        return dp[i][j][need]=ans;
        
    }
   

int evaluateExp(string & exp) {
    int n=exp.length();
       vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
       int ans =getWays(0,n-1,1,exp,dp);
       return ans;
}