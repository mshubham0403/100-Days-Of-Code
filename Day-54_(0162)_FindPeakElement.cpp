#include<bits/stdc++.h>
using namespace std;
  //MS001
    

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

vector<int>nums= {91,102,5,6,23,12,87};

int ans  =findPeakElement(nums);
cout<<ans;
 cout<<endl;


return 0;
}
