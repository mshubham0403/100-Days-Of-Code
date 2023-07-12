#include<bits/stdc++.h>
using namespace std;
   //day-73
   //MS001;


int numWays(int nthStair,vector<int>&waysToget){
    if(nthStair==1){
        waysToget[nthStair]=1;
        return 1;
    }
    if(nthStair==2){
        waysToget[nthStair]=2;
        return 2;
    }
    if(waysToget[nthStair]!=0){
        return waysToget[nthStair];
    }
    int a = numWays(nthStair-1,waysToget);
    int b = numWays(nthStair-2,waysToget);
    int cnt =a+b;
    waysToget[nthStair]=cnt;
    return cnt;
}
  
    int climbStairs(int nStairs) {
       vector<int>waysToget(nStairs+1,0);
    int ans =numWays(nStairs,waysToget);
    return ans;
    }
       
int main(){



int ans = climbStairs(23);
cout<<ans<<"\n";
 cout<<endl;
return 0;
}
