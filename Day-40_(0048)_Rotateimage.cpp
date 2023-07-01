#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty())
      return {};

    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<int> ans;
    int br = 0;
    int bc = 0;
    int er = m - 1;
    int ec = n - 1;

   
    while (br<=er && bc<=ec) {
      for (int j = bc; j <= ec && ans.size() < m * n; j++)
        ans.emplace_back(matrix[br][j]);
      for (int i = br + 1; i <= er - 1 && ans.size() < m * n; i++)
        ans.emplace_back(matrix[i][ec]);
      for (int j = ec; j >=bc  && ans.size() < m * n; j--)
        ans.emplace_back(matrix[er][j]);
      for (int i = er- 1; i >= br + 1 && ans.size() < m * n; i--)
        ans.emplace_back(matrix[i][bc]);
      br++, bc++, er--, ec--;
    }

    return ans;
  }
int main(){
vector<vector<int>> nums={{1,2,3},{8,99,45},{0,21,0}};

 vector<int> ans = spiralOrder(nums);
for(auto &x:ans){
   
        cout<<x<<" ";
    
}
cout<<endl;


return 0;
}
