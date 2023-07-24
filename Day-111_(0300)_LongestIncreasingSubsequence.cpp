#include<bits/stdc++.h>
using namespace std;
   //day-111
  //MS001;


 int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            auto ind  =lower_bound(ans.begin(),ans.end(),nums[i]);
            if(ind!=ans.end()){
                *(ind) =nums[i];
            }
            else{
                ans.push_back(nums[i]);
            } 
        }
        int len =ans.size();
        return len;
    }