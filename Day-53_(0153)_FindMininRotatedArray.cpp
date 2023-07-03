#include<bits/stdc++.h>
using namespace std;
  //MS001
    
  int findMin(vector<int>& nums) {
  int ans=0;
     int low=0,n=nums.size();
      int high=n-1;
      int minp=INT_MAX;
while(low<=high){
    int mid=low+((high-low));
    if(nums[low]<nums[mid]){
        minp=min(minp,nums[low]);
        low=mid+1;
    }
    else{
        minp=min(minp,nums[mid]);
        high=mid-1;
    }
}      
      ans=minp;
      return ans;
  
  }
int main(){

vector<int>nums= {91,102,5,6,23,12,87};

int ans  =findMin(nums);
cout<<ans;
 cout<<endl;


return 0;
}
