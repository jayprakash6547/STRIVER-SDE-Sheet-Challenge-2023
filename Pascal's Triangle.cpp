#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
   // is mujhe hr baar 1st velue 1 se start krni h to main ky karunga ki jb main 1st value print karunga na tb hi se us value ko hr baar replicate kr dunga aur uske replicate value ka sum krta jayunga to ans aa jayaga
        vector<vector<long long int>> r(n);
        for(int i=0;i<n;i++){
            r[i].resize(i+1);
            r[i][0]=r[i][i]=1;
            for(int j=1;j<i;j++)
                r[i][j]=r[i-1][j-1]+r[i-1][j];
        }
        return r;
}
