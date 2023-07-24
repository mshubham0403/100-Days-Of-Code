#include<bits/stdc++.h>
using namespace std;
   //day-112
  //MS001;


 vector<int> printingLongestIncreasingSubsequence(vector<int> nums, int n) {

        vector<int>dp(n+1,1);
		vector<int>prev(n+1,0);
		vector<int>ans;
		vector<int> lis(2,-1e9);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
            	if(nums[j]<nums[i]) {
        			if (dp[j] + 1 > dp[i]) {
          				dp[i] = dp[j] + 1;
          				prev[i] = j;
        			}
            	}
            }
            if(dp[i]==1){
        		prev[i] = i;
			}
		    if(dp[i]>lis[1]){
				lis[1]=dp[i];
				lis[0]=i;
			}
        }
		int prevLIS =prev[lis[0]];
		int lastLIS =lis[0];
		while(prevLIS!=lastLIS){
			ans.push_back(nums[lastLIS]);
			lastLIS=prevLIS;
			prevLIS=prev[lastLIS];
		}
		ans.push_back(nums[lastLIS]);
		reverse(ans.begin(),ans.end());
        return ans;
    }
