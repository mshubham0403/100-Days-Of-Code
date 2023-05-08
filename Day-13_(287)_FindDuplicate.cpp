#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

  int findDuplicate(vector<int>& nums) {
        int tor=nums[nums[0]];
        int rab=nums[nums[nums[0]]];
      
        while(rab!=tor){
            rab = nums[nums[rab]];
            tor = nums[tor];
        }
        tor=nums[0];
        while(rab!=tor){
            rab=nums[rab];
            tor=nums[tor]; 
        }
        return rab;
    }
int main(){
vector<int>nums={2,1,3,4,5,8,7,9,6,10,13,12,11,14};

int ans = findDuplicate(nums);
cout<<ans<<endl;

return 0;
}