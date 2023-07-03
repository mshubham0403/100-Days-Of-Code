#include<bits/stdc++.h>
using namespace std;

  void mergeArr(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1,j=n-1,fill=n+m-1;
      while(i>=0 && j>=0 && fill>=0){
          if(nums1[i]>nums2[j]){
              nums1[fill--]=nums1[i--];
          }
          else{
              nums1[fill--]=nums2[j--];  
          }
      }
      while(i>=0 && fill>=0){
          nums1[fill--]=nums1[i--];
      }
      while(j>=0 && fill>=0){
          nums1[fill--]=nums2[j--];
      }
      
  }
int main(){

vector<int>nums1= {1,2,5,6,23,12,87};
vector<int>nums2={22,45,123,3221,4565,12224465};
 mergeArr(nums1,13,nums2,6);
for(auto &x:nums1){
  
        cout<<x<<" ";
  
}
 cout<<endl;


return 0;
}
