#include<bits/stdc++.h>
using namespace std;

      void nextPermutation(vector<int>& nums) {
       if(nums.size()<=1){
           return ;
       }
        int r = nums.size() - 1;
        int itr = r-1;
        int inf = r;
        while (itr >= 0){
            if(nums[itr+1] <= nums[itr]) {
            itr--;
            }
            else{
                break;
            }
        }
     
       if(itr>=0){ 
        while(inf>=itr){
            if(nums[itr]>=nums[inf]){
            inf--;
            }
            else{
                break;
            }
        }
          
           int temp =nums[itr];
           nums[itr]=nums[inf];
           nums[inf]=temp;
          
        
       }

             ++itr;
             while(itr<=r){
                 swap(nums[itr],nums[r]);
                 r--;itr++;
             }
       
             return;
         }
int main(){
vector<int>nums={1-2,-3,-1,4,-3,-6,-5,12,34,56};

 nextPermutation(nums);
for(auto& x:nums){
    cout<<x<<" ";
}
cout<<endl;


return 0;
}
