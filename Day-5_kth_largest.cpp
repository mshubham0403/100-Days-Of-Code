#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


 int correctPlace(int l,int r,vector<int>&nums,int k){
        int tmp =0;
        auto point=l;
        int piv = nums[r];
        for (auto it =l;it<r;it++){
            if(nums[it]<=piv){
            tmp=nums[it];
            nums[it]=nums[point];
            nums[point]=tmp;
                point++;
            }
        }

        tmp = nums[point];
        nums[point]=nums[r];
        nums[r]=tmp;
        int indx = point;
        if(k==indx){
            return nums[indx];
        }
        else if(k>indx){
            return correctPlace(point+1,r,nums,k);
        }
        else{

        return correctPlace(l,point-1,nums,k) ;
        }
    }


    int findKthLargest(vector<int>& nums, int k) {
     int ans =correctPlace(0,nums.size()-1,nums,nums.size()-k);
     return ans;
            
             }
  

int main(){

vector<int> nums ={1,44,54,23,12,90};
int k=2;
int ans = findKthLargest(nums,k);
cout<<ans<<endl;


return 0;
}