#include<bits/stdc++.h>
using namespace std;

  long long minCost(vector<int>& nums, vector<int>& cost) {
    long long ans = 0;
    int l = *min_element(nums.begin(), nums.end());
    int r = *max_element(nums.begin(), nums.end());

    while (l < r) {
      int m = (l + r) / 2;
      long long cost1 = getCost(nums, cost, m);
      long long cost2 = getCost(nums, cost, m + 1);
      ans = min(cost1, cost2);
      if (cost1 < cost2)
        r = m;
      else
        l = m + 1;
    }

    return ans;
  }

 
  long long getCost(const vector<int>& nums, const vector<int>& cost,
                    int target) {
    long long res = 0;
    for (int i = 0; i < nums.size(); ++i)
      res += abs(nums[i] - target) * static_cast<long long>(cost[i]);
    return res;
  }
int main(){
vector<int>nums={3,4,54,12,33,7,87,9,12,13,43,14,15,18,21,19,23,25,24,26,27,28,29,11};
vector<int>cost ={45,1,11,2,12,13,44,5,65,76,8,77,88,65,4,44,34,76,88,78,3,98,98,7};
long long ans = minCost(nums,cost);
cout<<ans<<endl;

return 0;
}