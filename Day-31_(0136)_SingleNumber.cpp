#include<bits/stdc++.h>
using namespace std;

  
   vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m1;
        pair<int,int> p1;
        vector<int> ans;
        for (int i=0;i<nums.size();i++){
            m1.emplace(nums[i],i);
        }
        for (int j=0;j<nums.size();j++){
            int chk=target-nums[j];
            if(m1.find(chk)!=m1.end() && m1[chk]!=j){
                p1.first = j;
                p1.second = m1[chk];
            }
            
        }
        ans.emplace_back(p1.first);
        ans.emplace_back(p1.second);

        return ans;

    }
int main(){
vector<int>nums={1,2,3,7,4,4,9,5};

 vector<int> ans =twoSum(nums,8);
for(auto &x:ans){
  
        cout<<x<<" ";
    }
cout<<endl;


return 0;
}
