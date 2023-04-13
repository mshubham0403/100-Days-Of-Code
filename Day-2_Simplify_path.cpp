class Solution {
public:
    string simplifyPath(string path) {
        deque<string>simp;
        vector<string> fin;
     vector <string>splits;
     stringstream ss1 (path);
     char lit ='/';
     string wo;
     while(getline(ss1,wo,lit)){
         splits.emplace_back(wo);
     }
    
        string ans="";
        for (int i=0;i<splits.size();i++){
           
            if(splits[i]=="."){
              
                continue;
               
            }
            else if(splits[i]==".."){
               if(!simp.empty()){
      
                simp.pop_back();
               }
               
            }
           
            else{
                if(splits[i]!=""){

               
                simp.push_back(splits[i]);
                }
            }
        }
        while(!simp.empty()){
            if(simp.front()!=""){
               fin.emplace_back(simp.front());
              simp.pop_front();
         }
            }
        for (auto j =fin.begin();j!=fin.end();j++){
              string toadd ="/"+(*j);
              ans+=toadd;
          
        }
        if(ans==""){
            ans="/";
        }
        return ans;
    }
};
