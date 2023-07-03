#include<bits/stdc++.h>
using namespace std;
 int searchInsert(vector<int>& nums, int target) {
      //MS001
    int n =nums.size();
      int low=0,high=n-1;
      if(target>nums[n-1]) return n;
      if(target<nums[0]) return 0;
      while(low<=high){
          int mid=low+((high-low)/2);
          if(nums[mid]==target){
              return mid;
          }
          else if(nums[mid]>target){
              if(nums[mid-1]<target){return mid;}
              high=mid-1;
          }
          else{
              if(nums[mid+1]>target){
                  return mid+1;
              }
              low=mid+1;
          }
      }
      return -1;
      
  }
int main(){

vector<int>nums= {1,2,5,6,23,12,87};

int ans  =searchInsert(nums,5);
cout<<ans;
 cout<<endl;


return 0;
}
