#include<iostream>
using namespace std;

int main()
{
    int n,m;
    int target;

    cin>>n>>m;
    cin>>target;

    int mat[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }

        int r=0, c=m-1;
    while(r<n and c>=0)
    {
        if(mat[r][c]==target)
            return true;
        if(mat[r][c]>target)
            c--;
        else
            r++;
    }
    return false;

    return 0;
}
