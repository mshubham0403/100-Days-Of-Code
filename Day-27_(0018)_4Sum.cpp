#include<bits/stdc++.h>
using namespace std;

  vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
       int N =nums.size();
        sort(nums.begin(),nums.end());
        for(int i =0;i<N;i++){
            while(i>0 &&i<N && nums[i-1]==nums[i]){ i++;}
            for(int j=i+1;j<N;j++){
               while(j>i+1 &&j<N &&nums[j-1]==nums[j]) {j++;}
               int k=j+1;
                int l= N-1;
                while(k<l){
                  long long   sum=nums[i]+nums[j];
                      sum+=nums[k];
                      sum+=nums[l];
                    if(sum>target){
                        l--;
                    }
                    else if(sum<target){
                        k++;
                    }
                    else{
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;l--;
                        while(k<l && nums[k-1]==nums[k])k++;
                        while(k<l && nums[l+1]==nums[l])l--;
                        
                    }
                }
        }
        }

        return ans;
    }
int main(){
vector<int>nums={1,12,14,12,11,13,15,11,16,21,33,321,123,145,221,-11,-12,-13,121,-121,-323};

vector<vector<int>> ans = fourSum(nums,67);
for(auto&x:ans){
    for(auto&i:x){
        cout<<i<<" ";
    }
    cout<<endl;
}

return 0;
}