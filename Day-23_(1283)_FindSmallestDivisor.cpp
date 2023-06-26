#include<bits/stdc++.h>
using namespace std;

   //MS001
    bool testMid(vector<int>&nums,int mid,int limit){
        long long sum=0;
        for(auto &x:nums){
            int q=x%mid?(x/mid)+1:x/mid;
            sum+=q;
        }
        if(sum>limit){
            return false;
        }
        else{
            return true;
        }
    }
  int smallestDivisor(vector<int>& nums, int threshold) {
  int n=nums.size(),low=1,high=INT_MIN;
      int ans=INT_MAX;
      for(int i=0;i<n;i++){
         
          high=max(high,nums[i]);
      }
      while(low<=high){
          int mid=low+((high-low)/2);
          if(testMid(nums,mid,threshold)){
              ans=min(ans,mid);
              high=mid-1;
              cout<<"high "<<high<<endl;
          }
          else{
              low=mid+1;
              cout<<"low "<<low<<endl;
          }
          
      }
      return ans;
  }
int main(){
vector<int>nums={3,4,54,12,33,7,87,9,12,13,43,14,15,18,21,19,23,25,24,26,27,28,29,11};

int ans = smallestDivisor(nums,23);
cout<<ans<<endl;

return 0;
}