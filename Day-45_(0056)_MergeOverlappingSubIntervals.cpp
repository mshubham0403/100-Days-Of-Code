#include<bits/stdc++.h>
using namespace std;

  vector<vector<int>> mergeInt(vector<vector<int>>& sep) {
    vector<vector<int>> ans;
      sort(sep.begin(),sep.end());
   
      int s1=sep[0][0],s2=0,e1=sep[0][1],e2=0;
      for(int i=0;i<sep.size();i++){
          if(sep[i][0]<=e1){
              e1=max(sep[i][1],e1);
             
          }
          else if(sep[i][0]>e1){
              ans.push_back({s1,e1});
              s1=sep[i][0];
              e1=sep[i][1];
          }
      }
      ans.push_back({s1,e1});
      
        


    return ans;
  }
int main(){

vector<vector<int>>nums= {{1,3},{2,6},{1,4},{3,5},{4,9},{7,14}};
vector<vector<int>> ans = mergeInt(nums);
for(auto &x:ans){
   for(auto&i:x){
        cout<<i<<" ";
        
   }
   cout<<endl;
}



return 0;
}
