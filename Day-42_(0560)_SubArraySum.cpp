#include<bits/stdc++.h>
using namespace std;

 int subarraySum(vector<int>& nums, int k) {
    int ans = 0;
   unordered_map<int,int>sumH;
      int N=nums.size();
      long long sumCurr;
      sumH[0]=1;
      for(int i=0;i<N;i++){
          sumCurr+=nums[i];
          ans+=sumH[sumCurr-k];
          sumH[sumCurr]++;
          
      }

    return ans;
  }
int main(){
vector<int> nums={1,2,4,4,46,121,12,33,33,43,12,0,1,12,12,13,14,15,12};

 int ans = subarraySum(nums,3);
// for(auto &x:ans){
   
//         cout<<x<<" ";
    
// }
cout<<ans; 
cout<<endl;


return 0;
}


