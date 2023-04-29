// 1697. Checking Existence of Edge Length Limited Paths
#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;




 static bool comp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}

int findParent(int a,vector<int> &parent){
  if(parent[a]==a){
return a;
  }
  return parent[a] = findParent(parent[a],parent);
}

void unionNodes(int a, int b,vector<int> &parent,vector<int> &rank){
   int parA =findParent(a,parent) ;int parB = findParent(b,parent);
  if ( parA!=parB){
        if(rank[parA]>rank[parB]){
             parent[parB]=parA;
             rank[parA]++;
        }
        else {
             parent[parA]=parB;
             rank[parB]++;
        }
      }
}
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
vector<int>parent(n);
vector<int>rank(n,1);
      vector<bool>ans(queries.size());
      int maxpossible=0;
      int j =0;
    
        for(int i=0;i<n;i++){
          parent[i]=i;
        }
          for(int i=0;i<queries.size();i++){
          queries[i].emplace_back(i);
        }

        sort(edgeList.begin(),edgeList.end(),comp);
        sort(queries.begin(),queries.end(),comp);
        
        for(int i=0;i<queries.size();i++){
            maxpossible = queries[i][2];
            while(j<edgeList.size() && edgeList[j][2]<maxpossible){
                 unionNodes(edgeList[j][0],edgeList[j][1],parent,rank);
                 j++;
            }
           if(findParent(queries[i][0],parent)==findParent(queries[i][1],parent)){
                 ans[queries[i][3]]=true;
           }
           else{
                   ans[queries[i][3]]=false;
           }
    
    }

    return ans;
        }

int main(){
vector<vector<int>>edgeList={{1,2,3},{1,2,1},{2,4,1},{2,4,2},{2,3,5}};
vector<vector<int>>queries={{1,2,5},{2,4,5}};
int n=5;
vector<bool>ans = distanceLimitedPathsExist(n,edgeList,queries);
for(auto i:ans){
    cout<<i<<endl;
}

return 0;
}