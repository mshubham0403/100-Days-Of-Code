#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

   vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
     
        unordered_map<int,int>freq;
        for(auto &x:nums){
            freq[x]++;
        }
       vector< vector<int>>CntToVal(nums.size()+1);
        for(auto &pair:freq){
            CntToVal[pair.second].push_back(pair.first);
        }
    
          
        int n =CntToVal.size();
        for(int i=n-1;i>=0;i--){
          if(ans.size()==k){
              break;
          }
            if(!CntToVal[i].empty()){
           
                for(auto &x:CntToVal[i]){
                    ans.push_back(x);
                }
            }
            }
           
        
        return ans;
    }
int main(){
vector<int>nums={3,4,5,7,7,8,99,99,99,5,2,4,7};

vector<int> ans = topKFrequent(nums,3);
for(auto &x: ans){
 cout<<x<<" ";
}

return 0;
}