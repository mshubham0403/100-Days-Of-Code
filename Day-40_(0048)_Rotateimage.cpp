#include<bits/stdc++.h>
using namespace std;

 void rotate(vector<vector<int>>& matrix) {
  int n =matrix.size();
      int m =matrix[0].size();
      for(int i=0;i<n;i++){
          for(int j=i+1;j<m;j++){
           swap(matrix[i][j],matrix[j][i]);
          }
          for(int j=0;j<m/2;j++){
              int sw =m-1-j;
              swap(matrix[i][j],matrix[i][sw]);
          }
      }
  }
int main(){
vector<vector<int>> nums={{1,2,3},{8,99,45},{0,21,0}};

 rotate(nums);
for(auto &x:nums){
    for(auto &i:x){
        cout<<i<<" ";
    }
}
cout<<endl;


return 0;
}
