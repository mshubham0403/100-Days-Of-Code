#include<bits/stdc++.h>
using namespace std;
   //day-110
  //MS001;


int maxProfit(vector<int>& prices) {
        int n=prices.size(),minB=prices[0],maxP=0,gain=0;
        for(int i=1;i<n;i++){
            if(prices[i]-minB>maxP){
                gain+=prices[i]-minB;
                maxP=0;
                minB=prices[i];
            }
            else{
                minB=min(minB,prices[i]);
            }
            
        }
        return gain;
    }