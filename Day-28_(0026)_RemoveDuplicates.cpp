

  #include<bits/stdc++.h>
using namespace std;

  int removeDuplicates(vector<int>& nums) {
      int i=0,j=1;
      for (;j<nums.size();j++){
          if(nums[j]!=nums[i]){
              nums[i+1]=nums[j];
              i++;
              
          }
          
      }
        return i+1;
    }
int main(){
vector<int>nums={1,12,14,12,11,13,15,11,16,21,33,321,123,145,221,-11,-12,-13,121,-121,-323};

int ans = removeDuplicates(nums);
cout<<ans<<endl;

return 0;
}