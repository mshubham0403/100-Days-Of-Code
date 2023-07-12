#include<bits/stdc++.h>
using namespace std;
   //day-73
   //MS001;


 int rob(vector<int>& nums) {
            int prev2=0;
            int prev=nums[0]; 
            for(int i=1;i<nums.size();i++){
                 int takeN =nums[i];
                 int notTakeN = prev; 
                 if(i>1){
                    takeN =nums[i]+prev2;
                 }
                 prev2 =prev;
                 prev= max(takeN,notTakeN);
                    
            }
            return prev;
      } 
int main(){


vector<int>nums= {2,13,5,67,54,33,15,68,12,24,88,64};
int ans = rob(nums);
cout<<ans<<"\n";
 cout<<endl;
return 0;
}
