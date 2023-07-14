#include<bits/stdc++.h>
using namespace std;
   //day-81
   //MS001;   
int uniquePaths(int m, int n) {
	vector<vector<int>>grid(2,vector<int>(n,1)) ;
	for(int i=1;i<m;i++){
        for (int j = 1; j < n; j++) {
        	grid[1][j] = grid[0][j] + grid[1][j - 1];
        }
        grid[0] = grid[1];
        grid[1][0] = 1;
    }
    return grid[0][n-1];
}
    
int main(){
int ans = uniquePaths(8,9);
cout<<ans<<"\n";
 cout<<endl;
return 0;
}
