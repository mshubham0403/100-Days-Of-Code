#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

   int maxArea(vector<int>& height) {
    int ans = INT_MIN;
    int l = 0;
    int tmp=0;
    int r = height.size() - 1;

    while (l < r) {
      int minHeight = min(height[l], height[r]);
      tmp=minHeight * (r - l);
      ans = max(ans, tmp);
      if (height[l] < height[r])
        ++l;
      else
        --r;
    }

    return ans;
  }
int main(){
vector<int>nums={2,1,3,4,5,8,7,9,6,10,13,12,11,14};

int ans = maxArea(nums);
cout<<ans<<endl;

return 0;
}