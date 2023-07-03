#include<bits/stdc++.h>
using namespace std;
   
  bool search2(vector<int>& nums, int target) {
   //MS001

    
    int high =nums.size()-1;
        int low = 0;
      int k =0;
       int n=nums.size();
 
        while(low<=high){
         int   midi =low+((high-low)/2);
       
            if(nums[midi]==target){
                return true;
            }
            if(nums[high]==nums[low] && nums[low]==nums[midi]){
                low++;high--;
                continue;
            }
    if(nums[low]<=nums[midi]){
                    if(target>=nums[low]&& nums[midi]>=target){
                      high=midi-1;
                    }
                else{
                    low=midi+1;
                }
            }
            else {       
            if(target>=nums[midi] && target<=nums[high]){
                low=midi+1;
            }
           
          
            else{
                high=midi-1;
            }
        }
        }
        return 0;
  }
int main(){

vector<int>nums= {91,102,5,6,6,6,23,12,87};

int ans  =search2(nums,6);
cout<<ans;
 cout<<endl;


return 0;
}
