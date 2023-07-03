#include<bits/stdc++.h>
using namespace std;
 int search(vector<int>& nums, int target) {
        int high =nums.size()-1;
        int low = 0;
        while(low<=high){
         int   mid =low+((high-low)/2);
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
int main(){

vector<int>nums= {1,2,5,6,23,12,87};

int ans  =search(nums,5);
cout<<ans;
 cout<<endl;


return 0;
}
