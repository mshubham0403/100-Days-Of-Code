#include<bits/stdc++.h>
using namespace std;

    vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> ans;
    int pos=0,neg=0;
      int N=nums.size();
      while(pos<N && neg<N){
          
      
      while(nums[pos]<0){
          pos++;
      }
            ans.push_back(nums[pos++]);
        while(nums[neg]>0){
            neg++;
        }
          ans.push_back(nums[neg++]);
          }
    return ans;
  }
int main(){
vector<int>nums={1-2,-3,-1,4,-3,-6,-5,12,34,56};

 vector<int>ans =rearrangeArray(nums);
for(auto& x:ans){
    cout<<x<<" ";
}
cout<<endl;


return 0;
}
