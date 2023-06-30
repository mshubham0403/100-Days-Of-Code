#include<bits/stdc++.h>
using namespace std;

   int maxProfit(vector<int>& prices) {
     int N=prices.size();
        int minI =prices[0],maxS=0,profit=0;
        for(int i=1;i<N;i++){
            profit=prices[i]-minI;
            maxS=max(profit,maxS);
            minI=min(minI,prices[i]);
        }
      
        return maxS;
    }
int main(){
vector<int>nums={11,11,3,3,3,3,3,55,55};

 int ans =maxProfit(nums);
cout<<ans;
cout<<endl;


return 0;
}
