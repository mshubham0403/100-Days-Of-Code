#include<bits/stdc++.h>
using namespace std;

  
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int num : nums) {
            res ^= num;
        }
        return res;
    }
int main(){
vector<int>nums={11,11,2,3,3,4,4,55,55};

 singleNumber(nums);
for(auto &x:nums){
  
        cout<<x<<" ";
    }
cout<<endl;


return 0;
}
