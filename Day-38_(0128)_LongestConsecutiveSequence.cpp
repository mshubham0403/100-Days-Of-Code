#include<bits/stdc++.h>
using namespace std;

       int longestConsecutive(vector<int>& nums) {
        int count=0,mx=0;
        int nn =nums.size();
        if (nn==0){
            return 0;
        }
        unordered_set<int> seq;
        for(auto &it: nums)  {
            seq.insert(it);
        }
        
        for(auto &x :seq){
            if(seq.find(x-1)==seq.end()){
   
                   count=1;
                  int  xi=x+1;
                while(seq.find(xi)!=seq.end()){
                    count++;
                    xi++;
                }
            }
            mx=max(mx,count);
            count=0;
        }
        return mx;
    }
int main(){
vector<int>nums={1-2,-3,-1,4,-3,-6,-5,12,34,56,57,58,1,2,3,4,5,6,9};

 int ans = longestConsecutive(nums);
cout<<ans;
cout<<endl;


return 0;
}
