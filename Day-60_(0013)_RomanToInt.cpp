#include<bits/stdc++.h>
using namespace std;
   //day-60
    // MS001
 int romanToInt(string s) {
        unordered_map<char, int> romToInt = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        char prev = 'M';
        int result = 0;

        for (int i = 0; i < s.length(); i++) {
            char ii = s[i];
            if (romToInt[prev] < romToInt[ii]) {
                result -= 2 * romToInt[prev];
                result += romToInt[ii];
                prev = ii;
            } else {
                result += romToInt[ii];
                prev = ii;
            }
        }

        return result;
    }
   int main(){

string s1  ="MCMIXVII";

int ans  =romanToInt(s1);
cout<<ans;
 cout<<endl;


return 0;
}
