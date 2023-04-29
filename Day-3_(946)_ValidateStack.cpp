#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
     int i = 0, j = 0, chk = 0;
        while (i < pushed.size())
            if (~chk && popped[j] == pushed[chk]){
                j++;
                chk--;
            }
            else 
            {
                chk++;
                i++;
                if (i < pushed.size()) 
                {
                    pushed[chk] = pushed[i];
                }
            }
        return !chk;
    }
};

int main(){

Solution s1= Solution();
vector<int> pushed={2,1,3,4,5};
vector<int> popped={4,5,3,1,2};

bool res = s1.validateStackSequences(pushed,popped);
cout<<res<<endl;


    return 0;
}