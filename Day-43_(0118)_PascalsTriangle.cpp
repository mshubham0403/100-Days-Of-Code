#include<bits/stdc++.h>
using namespace std;

 vector<int> majorityElement(vector<int>& nums) {
    vector<int> ans;  
      int mj1=INT_MAX;
      int mj2=INT_MIN;
      int c1=0,c2=0;
    for(int i=0;i<nums.size();i++){
        if(c1==0 && nums[i]!=mj2){
            mj1=nums[i];
            c1++;
        }
          else if(c2==0 && nums[i]!=mj1){
            mj2=nums[i];
            c2++;
        }
        else if(nums[i]==mj1 && nums[i]!=mj2){
            c1++;
        }
        else if(nums[i]==mj2 && nums[i]!=mj1){
            c2++;
        }
      
        else if(nums[i]!=mj2 && nums[i]!=mj1){
            c2--;
            c1--;
        }
    }
      cout<<"mj1 :"<<mj1<<" mj2 :"<<mj2<<endl;
      c1=0;c2=0;
    c1=count(nums.begin(),nums.end(),mj1);
          c2=count(nums.begin(),nums.end(),mj2);

      int chk = ((nums.size()/3));
      if(c1>chk){
         ans.push_back(mj1); 
      }
       if(c2>chk){
        ans.push_back(mj2);
      }
      
      sort(ans.begin(),ans.end());
    return ans;
  }
      
int main(){

vector<int>nums={1,2,3,2,3,2,1,3,3,2,2,1,2,3};
 vector<int> ans = majorityElement(nums);
for(auto &x:ans){
   
        cout<<x<<" ";
    
}
cout<<endl;


return 0;
}




