#include<bits/stdc++.h>
using namespace std;

 vector<int>nRow(int i){
        vector<int>rows;
        rows.push_back(1);
        for(int k=1;k<i;k++){
            rows.push_back(((rows[k-1]*(i-k))/k));
        } 
        return rows;
    }
    
      vector<vector<int>> generate(int numRows) {
            vector<vector<int>> ans;       
            for (int i=1;i<numRows+1;i++){
                ans.push_back(nRow(i));      
            }
            return ans;
      }
      
int main(){


 vector<int> ans = nRow(12);
for(auto &x:ans){
   
        cout<<x<<" ";
    
}
cout<<endl;


return 0;
}




