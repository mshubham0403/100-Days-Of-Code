#include<bits/stdc++.h>
using namespace std;

        void setZeroes(vector<vector<int>>& matrix) {
    set<int>cols;
      set<int>rows;
      int n=matrix.size();
      int m =matrix[0].size();
      for(int i =0;i<n;i++){
          for(int j=0;j<m;j++){
              if(matrix[i][j]==0){
                  rows.insert(i);
                  cols.insert(j);
              }
          }
      }
    for(auto &i:rows){
        cout<<i<<" "<<endl;
    }
       for(auto &j:cols){
        cout<<j<<" "<<endl;
    }
      for(auto &ai:rows){
          for(int i =0;i<m;i++){
              matrix[ai][i]=0;
          }
      }
      for(auto &aj:cols){
          for(int i =0;i<n;i++){
              matrix[i][aj]=0;
          }
      }
  }

int main(){
vector<vector<int>> nums={{1,2,3},{8,99,45},{0,21,0}};

 setZeroes(nums);
for(auto &x:nums){
    for(auto &i:x){
        cout<<i<<" ";
    }
}
cout<<endl;


return 0;
}
