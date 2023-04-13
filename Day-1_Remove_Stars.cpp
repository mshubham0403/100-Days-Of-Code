class Solution {
public:
    string removeStars(string s) {
        string ansS="";
        stack <char> recent;
        for (int i=0;i<s.length();i++){
            if(s[i]!='*'){
                recent.push(s[i]);
            }
            else{
                recent.pop();
            }
        }
        vector <char> ans (recent.size());
        for (int q=recent.size()-1;q>=0;q--){
            ans[q]=recent.top();
            recent.pop();
        }
         for (int qq=0;qq<ans.size();qq++){
            ansS+=ans[qq];
        }


        return ansS;
        
    }
};