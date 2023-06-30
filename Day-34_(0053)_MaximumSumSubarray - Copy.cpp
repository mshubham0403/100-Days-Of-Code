#include<bits/stdc++.h>
using namespace std;

   int maxSubArray(vector<int>& nums) {
       int maxS=INT_MIN;
        int sum=0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxS=max(maxS,sum);
            sum = sum>0?sum:0;
        }
        return maxS;
    }
int main(){
vector<int>nums={11,11,3,3,3,3,3,55,55};

 int ans = maxSubArray(nums);
cout<<ans;
cout<<endl;


return 0;
}
