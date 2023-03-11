//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    void dfs(int r,int c,int str,int stc,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<pair<int,int>> &ls,int n,int m){
         vis[r][c]=1;
           ls.push_back({r-str,c-stc});
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int newr=r+delr[i];
            int newc=c+delc[i];
            if(newr>=0 and newr<n and newc>=0 and newc<m and grid[newr][newc] and !vis[newr][newc]){
             
                dfs(newr,newc,str,stc,grid,vis,ls,n,m);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>> st;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] and !vis[i][j]){
                    vector<pair<int,int>> ls;
                    dfs(i,j,i,j,grid,vis,ls,n,m);
                    st.insert(ls);
                }
            }    
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends