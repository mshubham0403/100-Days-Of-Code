#include<bits/stdc++.h>
using namespace std;

   bool isPossible(vector<int>arr,int day,int flowers,int bouqs){
        
        int adj=0;
        int bouq=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day){
                adj++;
                if(adj==flowers){
                    bouq++;
                    adj=0;
                    if(bouq==bouqs){
                        return true;
                    }
                }
            }
            else{
                adj=0;
            }
        }
        return false;
    }
  int minDays(vector<int>& bl, int m, int k) {
    long long days=INT_MAX,n=bl.size();
     long long reqFlowers=k;
      reqFlowers*=m;
      if(n<reqFlowers){return -1;}
      long long low=INT_MAX,high=INT_MIN;
      for(int i=0;i<n;i++){
          low=low<bl[i]?low:bl[i];
          high=high>bl[i]?high:bl[i];
      }
      while(low<=high){
          long long mid=low+((high-low)/2);
          bool ans=isPossible(bl,mid,k,m);
          if(ans){
              days =min(days,mid);
              high=mid-1;
          }
          else{
              low=mid+1;
          }
      }
    return days;
  }
int main(){
vector<int>nums={3,4,54,12,33,7,87,9,12,13,43,14,15,18,21,19,23,25,24,26,27,28,29,11};

int ans = minDays(nums,2,5);
cout<<ans<<endl;

return 0;
}