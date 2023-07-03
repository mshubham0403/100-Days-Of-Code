#include<bits/stdc++.h>
using namespace std;
   //MS001
  vector<int> searchRange(vector<int>& nums, int target) {
     int high =nums.size()-1;
        int low = 0;
        while(low<=high){
         int   mid =low+((high-low)/2);
            if(nums[mid]==target){
                int i=mid,j=mid;
                while(i-1>=0){
                   if(nums[i-1]==nums[mid]) i--;
                   else break;
                }
                while(j+1<nums.size()){
                   if(nums[j+1]==nums[mid]) j++;
                   else break;
                }
                return {i,j};
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
int main(){

vector<int>nums= {1,2,5,5,5,6,23,12,87};

vector<int >ans  =searchRange(nums,5);
cout<<ans[0]<<" "<<ans[1];
 cout<<endl;


return 0;
}
