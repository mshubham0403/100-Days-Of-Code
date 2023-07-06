#include<bits/stdc++.h>
using namespace std;
   //day-63
    // MS001
  bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();
      vector<bool>visited(n,0);
    vector<int>  color (n,-1);
      queue<int> nodeLine;
for(int i =0;i<visited.size();i++){
          if(visited[i]==false){
              nodeLine.push(i);
          }

          while(!nodeLine.empty()){
               cout<<nodeLine.front()<<" at front";
              cout<<endl;
              int hgl = nodeLine.front();

                  visited[hgl]=true;
                  if(color[hgl]==-1){
                      color[hgl]=1;
                      cout<<hgl<<" has color "<<"1"<<endl;;
                  }
                for(int i=0;i<graph[hgl].size();i++){
                    if(!visited[graph[hgl][i]]){
                        nodeLine.push(graph[hgl][i]);
                        cout<<"added in q "<<graph[hgl][i]<<endl;
                        visited[graph[hgl][i]]=true;
                    }
                    if(color[graph[hgl][i]]!=-1){
                        if(color[graph[hgl][i]]==color[hgl]){
                            cout<<"terminate because "<<graph[hgl][i]<<" and "<<hgl<<"color is"<<color[hgl]<<" matched"<<endl;
                            return false;
                        }
                    }
                    else{
                        color[graph[hgl][i]]= !color[hgl];
                        cout<<graph[hgl][i]<<" is given "<<!color[hgl]<<"color"<<endl;
                    }
                }
               cout<<nodeLine.front()<<" at front";
              cout<<endl;
              nodeLine.pop(); 
             }
        }
      return true;
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
                                {8,7,9}
};

bool ans = isBipartite(graph);
cout<<ans;
 cout<<endl;


return 0;
}
