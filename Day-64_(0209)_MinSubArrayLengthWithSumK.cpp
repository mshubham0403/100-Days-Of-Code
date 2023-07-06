#include<bits/stdc++.h>
using namespace std;
   //day-64
    // MS001
 
    int minSubArrayLen(vector<int>& nums,int target) {
        int i=0;
        long long sumi=0;
        long long sumj=0;
int flag =1;
        int ans=INT_MAX;
        for(int j=0;j<nums.size();j++){
            if (sumi+nums[j]<target){
                sumi+=nums[j];
            }
            else{
                flag= 0;
                sumi+=nums[j];
                cout<<"sum sfter adding "<<nums[j]<<" "<<sumi<<endl;
                ans=min(ans,j-i+1);
                while((sumi-nums[i])>=target){
                 sumi-=nums[i++];
                   cout<< "sumi "<<sumi<<endl;
                }
                ans =min(ans,j-i+1);
                cout<<"ans "<<ans<<" j "<<j<<" i "<<i<<endl;
            }

        }
        if(flag){return 0;}
        return ans;
    }

   int main(){

vector<int> nums ={1,3,13,4,54,6,7,14,12,76,3};


int ans = minSubArrayLen(nums,24);
cout<<ans;
 cout<<endl;


return 0;
}
