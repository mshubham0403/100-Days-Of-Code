#include<bits/stdc++.h>
using namespace std;

 int singleNonDuplicate(vector<int>& nums) {
   int n=nums.size();
    if(n==1)return nums[0];
    if(nums[0]!=nums[1]) return nums[0];
    if(nums[n-1]!=nums[n-2]) return nums[n-1];
      int  low=1,high=n-2;
      while(low<=high){
          int mid=low+((high-low)/2);
          
                if(mid%2==0){
                    if(nums[mid+1]!=nums[mid] && nums[mid-1]!=nums[mid]){
                        return nums[mid];
                    }
                    else if(nums[mid+1]==nums[mid]){
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }
                }
              else{
                  if(nums[mid+1]!=nums[mid] && nums[mid-1]!=nums[mid]){
                        return nums[mid];
                    }
                    else if(nums[mid+1]!=nums[mid]){
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }
              }
          }
        
       
      
      return nums[0];
  }
int main(){
vector<int>nums={1,12,14,12,11,13,15,11,16,21,33,321,123,145,221,-11,-12,-13,121,-121,-323};

int ans = singleNonDuplicate(nums);
cout<<ans<<endl;

return 0;
}