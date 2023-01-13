/*
Submatrix Sum
Given a matrix of size M x N, there are large number of queries to find submatrix sums. Inputs to queries are left top and right bottom indexes of submatrix whose sum is to find out.
How to preprocess the matrix so that submatrix sum queries can be performed in O(1) time.
INPUT FORMAT:
Given a matrix (2d vector) and query.. Each query has Starting row, Starting column, Ending row, Ending column.
OUTPUT FORMAT:
A single integer which is the sum of the submatrix.
Example :
tli :  Row number of top left of query submatrix
tlj :  Column number of top left of query submatrix
rbi :  Row number of bottom right of query submatrix
rbj :  Column number of bottom right of query submatrix
Input: mat[M][N] = {{1, 2, 3, 4, 6},
                    {5, 3, 8, 1, 2},
                    {4, 6, 7, 5, 5},
                    {2, 4, 8, 9, 4} };
Query1: tli = 0, tlj = 0, rbi = 1, rbj = 1
Query2: tli = 2, tlj = 2, rbi = 3, rbj = 4
Query3: tli = 1, tlj = 2, rbi = 3, rbj = 3;

Output:
Query1: 11  // Sum between (0, 0) and (1, 1)
Query2: 38  // Sum between (2, 2) and (3, 4)
Query3: 38  // Sum between (1, 2) and (3, 3)
*/

#include<bits/stdc++.h>
using namespace std;

int sum(vector<vector<int>> v, int sr, int sc, int er, int ec){
    int m=v.size();
    int n=v[0].size();
    int M=m;
    int N=n;
    vector<vector<int>> aux = v;
    vector<vector<int>> mat = v;
    int tli=sr, tlj=sc, rbi=er, rbj=ec;
      for (int i=0; i<N; i++)
      aux[0][i] = mat[0][i];

  // Column wise sum
  for (int i=1; i<M; i++)
      for (int j=0; j<N; j++)
         aux[i][j] = mat[i][j] + aux[i-1][j];

  // Row wise sum
  for (int i=0; i<M; i++)
      for (int j=1; j<N; j++)
         aux[i][j] += aux[i][j-1];


    int res = aux[rbi][rbj];

    // Remove elements between (0, 0) and (tli-1, rbj)
    if (tli > 0)
       res = res - aux[tli-1][rbj];

    // Remove elements between (0, 0) and (rbi, tlj-1)
    if (tlj > 0)
       res = res - aux[rbi][tlj-1];

    // Add aux[tli-1][tlj-1] as elements between (0, 0)
    // and (tli-1, tlj-1) are subtracted twice
    if (tli > 0 and tlj > 0)
       res = res + aux[tli-1][tlj-1];

    return res;
}

