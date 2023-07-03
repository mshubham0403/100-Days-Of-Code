#include<bits/stdc++.h>
using namespace std;
 int maxProduct(vector<int>& nums) {
        int pre =1;
        int maxp =INT_MIN;
        int n=nums.size();
       int suff =1;
        for(int i=0;i<n;i++){
            
            pre=pre*nums[i];
            suff =suff*nums[n-1-i];
            maxp =max(maxp,max(pre,suff));
             if(pre==0){
                pre=1;
            }
            if(suff==0){
                suff=1;
            }
          
        }
     return maxp;   
    }
int main(){

vector<int>nums= {1,2,5,6,23,12,87};

int ans  =maxProduct(nums);
cout<<ans;
 cout<<endl;


return 0;
}
