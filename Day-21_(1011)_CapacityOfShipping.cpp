#include<bits/stdc++.h>
using namespace std;

  int calcDays(vector<int>weights,int capacity){
        int days=1;
        int weightOfItems = 0;
    for (const int weight : weights)
      if (weightOfItems + weight > capacity) {
        ++days;
        weightOfItems = weight;
      } else {
         weightOfItems += weight;
      }
    return days;
    }
    
  int shipWithinDays(vector<int>& weights, int days) {
  
      int high =accumulate(weights.begin(),weights.end(),0);
      int low =*max_element(weights.begin(),weights.end());
      cout<<"low high :"<<low<<" , "<<high<<endl;
      while(low<high){
          int mid=low+((high-low)/2);
          cout<<"mid "<<mid<<endl;
        int  daysForMidCapacity = calcDays(weights,mid);
          if(daysForMidCapacity>days){
              low=mid+1;
          }
          else{
            
              high=mid;
          }
      }
    return low;
  }
int main(){
vector<int>nums={3,4,54,12,33,7,87,9,12,13,43,14,15,18,21,19,23,25,24,26,27,28,29,11};

int ans = shipWithinDays(nums,3);
cout<<ans<<endl;

return 0;
}