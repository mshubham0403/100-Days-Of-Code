#include<bits/stdc++.h>
using namespace std;
   //day-66
   //MS001;
    void getPartitions(string s,int prevPart,int ind,vector<string>&tmp,vector<vector<string>>&ans){
        if(ind == s.length()){
            if(tmp.size()==0)return;
            if(prevPart!=ind-1){return;}
            ans.push_back(tmp);
            return ;
        } 
        //no new partition
        getPartitions(s,prevPart,ind+1,tmp,ans);
        //check if making partition at ind is valid
        int low=prevPart+1,high=ind;
        int isValid=1;
        string tmpS="";
        while(high>=low){
            if(s[low]!=s[high]){
                isValid=0;
                break;
            }
            tmpS+=s[low];
            high--;low++;
        }
        
        if(isValid){
            while(low<=ind){
                tmpS+=s[low++];
            }
            tmp.push_back(tmpS);
            getPartitions(s,ind,ind+1,tmp,ans);
            tmp.pop_back();
        }     
       return; 
    }
    
    
  vector<vector<string>> partition(string s) {
      vector<vector<string>> ans;
      vector<string>tmp;
      getPartitions(s, -1,0,tmp, ans);
      return ans;
  }
   int main(){

string s ="gooddayisfunnow";




vector<vector<string>> ans = partition(s);
for(auto &x:ans){

for(auto&i:x){
    cout<<i<<" ";
}
 cout<<endl;
}

return 0;
}
