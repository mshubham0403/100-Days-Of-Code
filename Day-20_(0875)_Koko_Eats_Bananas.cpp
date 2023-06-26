#include<bits/stdc++.h>
using namespace std;

  int minEatingSpeed(vector<int>& piles, int h) {
    int n=piles.size();
      int maxP=0;
      long long mink=INT_MAX;
   
      for(auto&i :piles){
          maxP=max(maxP,i);
      }
      int low=1;
      int high=2*maxP,best=h;;
      while(low<=high){
          long long mid=low+((high-low)/2);
          long long n=0;
          
          for(auto &i:piles){
              n+=i%mid?(i/mid)+1:i/mid;
          }
          if(n>h){
          
             
              cout<<"ans n>h"<<mink<<" n "<<n<<endl;
              low=mid+1;
          }
          else{
             
           
              mink=min(mink,mid);
              high=mid-1;
          }
          
      }
      return mink;
  }
int main(){
vector<int>nums={3,4,54,12,33,7,87,9,12,13,43,14,15,18,21,19,23,25,24,26,27,28,29,11};

int ans = minEatingSpeed(nums,3);
cout<<ans<<endl;

return 0;
}