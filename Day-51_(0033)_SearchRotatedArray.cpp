#include<bits/stdc++.h>
using namespace std;
   //MS001
  //MS001
  int searchRotated(vector<int>& nums, int target) {
    int high =nums.size()-1;
        int low = 0;
      int k =0;
      while(low<=high){
         int   mid =low+((high-low)/2);
            if(nums[mid]>=nums[low]){
                cout<<"first if "<<nums[mid]<<" "<<nums[low]<<endl;
                if(mid+1>high ||mid<low){
                    break;
                }
                if(nums[mid+1]>nums[mid]){cout<<"mid+1 "<<nums[mid+1]<<endl;low=mid+1;}
                else {k=mid+1;break;}
            }
            else {
                cout<<"first else "<<nums[mid]<<" "<<nums[low]<<endl;

                if(nums[mid-1]>nums[mid]){k=mid;break;}
                high=mid-1;
            }
       
          
        }
       int n=nums.size();
      low=k;high=n-1+k;
        while(low<=high){
         int   mid =low+((high-low)/2);
          int   midi=mid%n;
            if(nums[midi]==target){
                return midi;
            }
            else if(nums[midi]>target){
                high=mid-1;
               
            }
            else{
                low=mid+1;
            }
        }
        return -1;
  }
int main(){

vector<int>nums= {91,102,5,6,23,12,87};

int ans  =searchRotated(nums,5);
cout<<ans;
 cout<<endl;


return 0;
}
