#include<bits/stdc++.h>
using namespace std;
   //day-61
    // MS001
  int longestSubarray(vector<int>& nums) {
       vector<int>concise;
        int cnt=0;
        int flag=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
            }
            else{
                concise.push_back(cnt);
                flag=0;
                cnt=0;
            }
            
        }
         concise.push_back(cnt);
       int sumi=0;
        int maxi=concise[0];
        if(flag){
            return maxi-1;
        }
        for(auto&x:concise){
            cout<<x<<" ";
        }
        cout<<endl;
        for (int i=0;i<concise.size()-1;i++){
            sumi=concise[i+1]+concise[i];
            cout<<sumi<<endl;
            maxi=max(maxi,sumi);
        }
        return maxi;
    }
   int main(){

vector<int> nums = {0,1,1,1,0,0,1,1,1,0,1,0,1,1,1,1,1,1,0,1,1,1,1};

int ans  =longestSubarray(nums);
cout<<ans;
 cout<<endl;


return 0;
}
