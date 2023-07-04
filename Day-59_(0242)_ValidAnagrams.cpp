#include<bits/stdc++.h>
using namespace std;
   //day-59
    // MS001
bool isAnagram(string s, string t) {
       int strtpin =int('a');
        vector<int>countAlphaS(26,0) ;
        vector<int>countAlphaT(countAlphaS);
        int index;
        for (auto c :s){
            index = int(c)-strtpin;
            countAlphaS[index]++;

        }
        for(auto ch:t){
            index =int(ch)-strtpin;
            countAlphaT[index]++;

        }
        for(int i=0;i<26;i++){
            if(countAlphaS[i]!=countAlphaT[i]){
                return false;
            }

        }
        return true;
    }
   int main(){

string s1  ="uroohhooru";
string s2 = "roohuuhoor";

bool ans  =isAnagram(s1,s2);
cout<<ans;
 cout<<endl;


return 0;
}
