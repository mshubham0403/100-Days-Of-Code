#include<bits/stdc++.h>
using namespace std;
   //day-78
    // MS001
  bool getSafe(int node ,vector<vector<int>>&graph,vector<int>&path,vector<bool>&visited,vector<int>&finals){
        if(graph[node].size()==0){
            finals[node]=1;
            return true;
        }
        
        if(finals[node]==1) return true;
       
        if(visited[node] ||finals[node]==-1){
            for(int i=path.size()-1;i>-1;i--){
                finals[path[i]]=-1;
            }
            path.clear();
            return false;
        }
        
        if(!visited[node]){
            path.push_back(node);
            visited[node]=1;
            for(int i=0;i<graph[node].size();i++){
                
                bool isSafe = getSafe(graph[node][i],graph,path,visited,finals);
               
                if(!isSafe){
                    return false;
                }       
            }
            finals[node]=1;
            path.pop_back();
            return true;
        }
   
        return true;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       int n=graph.size();
        vector<bool>visited(n,false);
        vector<int>path;
        vector<int>finals(n,-2);
        vector<int>ans;
      
        for(int i=0;i<graph.size();i++){
          if(finals[i]==-1) continue;
          if(finals[i]==1)continue;
          bool ians =getSafe(i,graph,path,visited,finals); 
        }
        for(int i=0;i<n;i++){
            if(finals[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
   int main(){

vector < vector<int> > graph = {
                                {0,2,5},
                                {1,5,8,6},
                                {7,1,6,9},
                                {4,3,8,9},
                                {4,8,3,1},
                                {7,2,6},
                                {6,2,8},
                                {4,1,9,5},
                                {8,7,1}
};

vector<int> ans = eventualSafeNodes(graph);
for(auto&x :ans){
    cout<<x<<" ";
}
 cout<<endl; 
return 0;
}
