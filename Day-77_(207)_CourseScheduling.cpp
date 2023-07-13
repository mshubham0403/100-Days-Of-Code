#include<bits/stdc++.h>
using namespace std;
   //day-77
    // MS001
 
    bool isValid(int node,vector<vector<int>>&reqs,vector<bool>visited,vector<int>&path,vector<int>&done){
        if(visited[node]==true){
            return false;
        }
        if(reqs[node].size()==0){
            return true;
        }
        if(done[node]==1){
            return true;
        }
        visited[node]=true;
        for(int i=0;i<reqs[node].size();i++){
            bool valid = isValid(reqs[node][i],reqs,visited,path,done);
            if(!valid) return false;
        }
        done[node]=1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>>reqs(numCourses);
        vector<bool>visited(numCourses,false);
        vector<int>path;
        vector<int>done(numCourses,-2);
        for(int i=0;i<prereq.size();i++){
            reqs[prereq[i][0]].push_back(prereq[i][1]);
        }
        for(int i=0;i<numCourses;i++){
           bool valid = isValid(i,reqs,visited,path,done);
            if(!valid) return false;
        }
        return true;
    }
   int main(){

vector<vector<int>> preReqs = {{1,0},
 {1,4},
 {4,2},
 {3,6},
 {6,2},
 {4,1},
 {3,4},
 {5,1},
 {6,2}};




bool ans = canFinish(6,preReqs);
cout<<ans;
 cout<<endl;


return 0;
}
