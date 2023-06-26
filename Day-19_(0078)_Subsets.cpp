
#include<bits/stdc++.h>
using namespace std;

   void powerSet(int i,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        powerSet(i+1,nums,temp,ans);
        temp.pop_back();
        powerSet(i+1,nums,temp,ans);
        return;
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        powerSet(0,nums,temp,ans);
        return ans;
    }
int main(){
vector<int>nums={3,4,5,7,7,8,99,99,99,5,2,4,7};

vector<vector<int>>ans = subsets(nums);
for(auto &x: ans){
    for(auto &i:x){
        cout<<i<<" ";
    }
    cout<<endl;
}

return 0;
}