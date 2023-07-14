#include<bits/stdc++.h>
using namespace std;
   //day-80
   //MS001;


 int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int>pred;
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            if(pred[arr[i]-diff]!=0){
                pred[arr[i]]=pred[arr[i]-diff]+1;
                maxi=max(maxi, pred[arr[i]]);
            }
            else{
                pred[arr[i]]=1;
                maxi=max(maxi, pred[arr[i]]);
            }
        }
        return maxi;
    }
int main(){


vector<int>nums= {2,13,5,67,54,33,15,68,12,24,88,64};
int ans = longestSubsequence(nums,8);
cout<<ans<<"\n";
 cout<<endl;
return 0;
}
