#include <bits/stdc++.h> 


void solve(int row,int col,vector<vector<int>>&ans,vector<int>&temp,vector<vector<int>>&pathvis,
vector<vector<int>>&maze,int n)
{
  if (col == n - 1 && row == n - 1) {
    ans.push_back(temp);
    return;
  }
  int del_row[] = {0,0,1,-1};
  int del_col[] = {1,-1,0,0};

  for(int i=0;i<4;i++)
  {
    int n_row = row+del_row[i];
    int n_col = col+del_col[i];
    if(n_row>=0 && n_row<n && n_col>=0  && n_col<n && pathvis[n_row][n_col]==0 && maze[n_row][n_col]==1)
    {
      pathvis[n_row][n_col] = 1;
      temp[n*n_row+n_col] = 1;

      solve(n_row,n_col,ans,temp,pathvis,maze,n);

      pathvis[n_row][n_col] = 0;
      temp[n*n_row+n_col] = 0;
    }
  }
  return;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<int> temp(n*n,0);
  vector<vector<int> >ans;
  vector<vector<int> > pathvis(n,vector<int>(n,0));
  pathvis[0][0]=1;
  temp[0]=1;
  solve(0,0,ans,temp,pathvis,maze,n);

  return ans;
}