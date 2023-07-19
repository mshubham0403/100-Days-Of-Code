#include<bits/stdc++.h>
using namespace std;

  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]<b[0]){
                return true;
            }
            else if(a[0]>b[0]){
                return false;
            }
            else{
                return a[1]<b[1];
            }
        });
        int n =intervals.size();
        vector<int>prev=intervals[0];
      int cnt=0;
        for(auto&x:intervals){
            for(auto&i:x){
                cout<<i<<",";
            }
            cout<<"  ";
        }
        for(int i=1;i<n;i++){
            if(prev[1]>intervals[i][0]){
                if(intervals[i][1]<prev[1]){
                    cnt++;
                    prev=intervals[i];
                }
                else{
                   cnt++;
                }
            }
            else{
                prev=intervals[i];
                continue; 
            }
            
        }
        return cnt;
        
    }
int main(){

vector<vector<int>>nums= {{1,3},{1,6},{1,4},{3,5},{4,9},{7,14}};
int ans = eraseOverlapIntervals(nums);

   cout<<ans<<" ";
        
  
   cout<<endl;




return 0;
}
