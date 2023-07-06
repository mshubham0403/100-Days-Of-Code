#include<bits/stdc++.h>
using namespace std;
   //day-65
    // MS001
 
  bool chkColor(int mColor , int node,vector<vector<int>>&edges,vector<int>&color){
    for(int i=0;i<edges[node].size();i++){
        if(color[edges[node][i]]==mColor){
            return false;
        }
    }
    return true;
}
bool isPossible(vector<vector<int>>&edges,vector<int>&color,int node,int maxNode,int m){
     if(node==maxNode){
         return true;
     }
     for(int i=1;i<=m;i++){
         if ( chkColor(i,node,edges,color) ){
             color[node] =i;
            int res= isPossible(edges,color,node+1,maxNode,m);
            if(res) return true;
         }
     }
     return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
  vector<vector<int>>edges;
  for(int i=0;i<mat.size();i++){
      vector<int>tmp;
      for(int j=0;j<mat[i].size();j++){
          if((mat[i][j])){
            tmp.push_back(j);
          }
      }
      edges.push_back(tmp);
  }
  int totalNodes=mat.size();
  vector<int>color(totalNodes,-1);
  bool boolAns =isPossible(edges,color,0,mat.size(),m);
  string ans = boolAns?"YES":"NO";
  return ans;
}
   int main(){

vector<vector<int>> graph = {{0, 0, 1, 0, 0, 1, 0, 0, 0},
 {0, 0, 1, 0, 0, 1, 1, 0, 1},
 {0, 1, 0, 0, 0, 0, 1, 0, 1},
 {0, 0, 0, 0, 1, 0, 0, 0, 1},
 {0, 1, 0, 1, 0, 0, 0, 0, 1},
 {0, 0, 1, 0, 0, 0, 1, 0, 0},
 {0, 0, 1, 0, 0, 1, 0, 0, 1},
 {0, 1, 0, 0, 1, 0, 0, 0, 1},
 {0, 0, 0, 0, 0, 0, 0, 1, 0}};




string ans = graphColoring(graph,4);
cout<<ans;
 cout<<endl;


return 0;
}
