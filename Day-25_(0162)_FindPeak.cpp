#include<bits/stdc++.h>
using namespace std;

   int findPeakElement(vector<int>& nums) {
   int n = nums.size();
      if(n==1) return 0;
      if(nums[n-1]>nums[n-2]) return n-1;
      if(nums[0]>nums[1]) return 0;
      int low=1,high=n-2;
      while(low<=high){
        int  mid =low+((high-low)/2);
          if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
              return mid;
          }
          else if(nums[mid+1]>nums[mid]){
              high=mid-1;
          }
          else{
              low=mid+1;
          }
      }
      low=1;high=n-2;
      while(low<=high){
        int  mid =low+((high-low)/2);
          if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
              return mid;
          }
          else if(nums[mid+1]<nums[mid]){
              high=mid-1;
          }
          else{
              low=mid+1;
          }
      }
      return 0;
      
  }
int main(){
vector<int>nums={2,3,4,12,15,17,29,23,24,22,19,11,10};

int ans = findPeakElement(nums);
cout<<ans<<endl;

return 0;
}