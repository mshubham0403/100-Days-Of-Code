#include<bits/stdc++.h>
using namespace std;

   int majorityElement(vector<int>& nums) {
    int hero=nums[0];
    int cnt=0;
        
        for(int i =0;i<nums.size();i++){
            if(hero==nums[i]){
                cnt++;
            }
            else{
                cnt--;
                if(cnt<0){
                    hero=nums[i];
                    cnt=1;
                }
            }
        }
        return hero;
    }
int main(){
vector<int>nums={11,11,3,3,3,3,3,55,55};

 int ans = majorityElement(nums);
cout<<ans;
cout<<endl;


return 0;
}
