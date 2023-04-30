#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

 int removeDuplicates(vector<int>& nums) {
      int i=0,j=1;
      for (;j<nums.size();j++){
          if(nums[j]!=nums[i]){
              nums[i+1]=nums[j];
              i++;
              
          }
          
      }
        return i+1;
    }

int main(){
vector<int>nums={1,1,1,2,2,3,4,4,5,6,7};
int ans = removeDuplicates(nums);
cout<<ans<<endl;
for(auto i :nums){
  cout<<i<<" ";
}
return 0;
}