#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

 bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>adj;
        for(auto i :edges){
            int u=i[0];
            int v=i[1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        vector<int> visited(n,0);
        queue<int>curr;
        curr.push(source);
        while(!curr.empty()){
            int u =curr.front();
            visited[u]=1;
            curr.pop();
            for (auto i :adj[u]){
                    if (visited[i]==0){
                    curr.push(i);
                    visited[i]=1;}     
            }
        }
        if(visited[destination]==0){
            return false;
        }
        else{
            return true;
        }

    }
int main(){
vector<vector<int>>edges= {{1,0},{1,2},{2,3},{3,4},{4,0}};
int n=5,source=0,destination=4;
bool ans = validPath(n,edges,source,destination);
cout<<ans<<endl;

return 0;
}