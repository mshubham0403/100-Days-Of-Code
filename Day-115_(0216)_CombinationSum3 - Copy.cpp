#include<bits/stdc++.h>
using namespace std;
   //day-115
  //MS001;

 void getWays(int num,int target,int k,vector<int>curr,vector<vector<int>>&ans){
        if(target==0 && k==0){
            ans.push_back(curr);
        }
        if(k==0){
            return;
        }
        for(int i=num;i<=9;i++){
            if(i>target)break;
            curr.push_back(i);
            getWays(i+1,target-i,k-1,curr,ans);
            curr.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>curr;
        getWays(1,n,k,curr,ans);
        return ans ;
    }