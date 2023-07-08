#include<bits/stdc++.h>
using namespace std;
   //day-68
   //MS001;
void getPaths(vector<vector<int>>&maze,pair<int,int>ind,int n,vector<vector<int>>&ans,vector<vector<int>>&allAns){
  if(ind.first==n-1 && ind.second==n-1){
    ans[n-1][n-1]=1;
    vector<int>path;
    for(auto &x:ans){
      for(auto &i:x){
        path.push_back(i);
      }
    }
     allAns.push_back(path);
     ans[n-1][n-1]=0;
    return ;
  }
  int up=0,down=0,left=0,right=0;
  ans[ind.first][ind.second]=1;
  //check up
  if(ind.first-1 > -1){
    if(maze[ind.first-1][ind.second] && !ans[ind.first-1][ind.second]){
      up=1;
      getPaths(maze, {ind.first - 1, ind.second}, n, ans, allAns);
    }
  }
  //check left
  if(ind.second-1 >-1){
    if(maze[ind.first][ind.second-1]&& !ans[ind.first][ind.second-1]){
      left=1;
      getPaths(maze, {ind.first, ind.second - 1}, n, ans, allAns);
    }
  }
  //check down
  if(ind.first+1 <n){
    if(maze[ind.first+1][ind.second] && !ans[ind.first+1][ind.second]){
      down=1;
      getPaths(maze, {ind.first + 1, ind.second}, n, ans, allAns);
    }
  }
   //check right
  if(ind.second+1<n){
    if(maze[ind.first][ind.second+1] && !ans[ind.first][ind.second+1]){
      right=1;
      getPaths(maze, {ind.first, ind.second + 1}, n, ans, allAns);
    }
  }
  ans[ind.first][ind.second]=0;
  return;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>> ans(n,vector<int>(n,0));
  vector<vector<int>> allAns;
 
  getPaths(maze,{0,0},n,ans,allAns);

  return allAns;
  

}

int main(){

vector<vector<int>>maze ={{1,0,0},{1,1,0},{0,1,1}};
vector<vector<int>> ans = ratInAMaze(maze,3);

for(auto &x:ans){
    for(auto&i:x){
        cout<<i<<" ";
    }
 cout<<endl;
}

return 0;
}
