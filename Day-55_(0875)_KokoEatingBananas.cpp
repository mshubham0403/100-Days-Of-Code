#include<bits/stdc++.h>
using namespace std;
   //day-55
    

     //MS001
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

vector<int>nums= {91,102,5,6,23,12,87,43,12,87,98,11};

int ans  =minEatingSpeed(nums,18);
cout<<ans;
 cout<<endl;


return 0;
}
