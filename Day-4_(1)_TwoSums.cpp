#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
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
};


int main(){
Solution s1= Solution();
vector<int> nums={1,2,3,4,5,12,44};
int trg = 15;
vector<int> ans = s1.twoSum(nums,trg);
cout<<ans[0]<<" "<<ans[1]<<endl;
return 0;
}