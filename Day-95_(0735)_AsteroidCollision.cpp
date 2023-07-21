#include<bits/stdc++.h>
using namespace std;
   //day-94
  //MS001;


  vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            if(!st.empty() && st.top()>0 && asteroids[i]<0){
                while(st.top()<abs(asteroids[i]) && st.top()>0){
                    st.pop();
                    if(st.empty()){
                        break;
                    }
                }
                if(st.empty() || st.top()<0){
                    st.push(asteroids[i]);
                }
                else if(st.top()==abs(asteroids[i])){
                    st.pop();
                }
            }
            else{
                st.push(asteroids[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        int n=ans.size();
        for(int i=0;i<(n/2);i++){
            int tmp=ans[i];
            ans[i]=ans[n-1-i];
            ans[n-1-i]=tmp;
        }
        return ans;
    }
int main(){


vector<int>asteroids= {2,13,5 ,-23,-12,33,4,5,-2,-8};


vector<int> ans = asteroidCollision(asteroids);
for(auto&x:ans){
	cout<<x<<" ";
}
 cout<<"\n";
return 0;
}
