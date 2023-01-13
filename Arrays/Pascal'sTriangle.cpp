/*
Pascal’s triangle is a triangular array of the binomial coefficients. Write a function that takes an integer value n as input and returns 2D array with first n lines of the Pascal’s triangle.
Following are the first 5 rows of Pascal’s Triangle.
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
Input Format
In the function an integer N is passed.
Output Format
Return the output as vector of vectors.
*/

/// Solution 1

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> printPascal(int n)
{
    vector<vector<int>> result;
    for(int i=0;i<n;i++){
        result[i].resize(i+1);
        result[i][0]=result[i][i]=1;
        for(int j=1;j<i;j++){
            result[i][j]=result[i-1][j-1]+result[i-1][j];
        }
    }
return result;
}

/// Solution 2

#include<bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k);

vector<vector<int>> printPascal(int n)
{
     vector<vector<int>> res;
    for (int line = 0; line < n; line++)
    {
        vector<int> v;
        for (int i = 0; i <= line; i++)
         {v.push_back(binomialCoeff(line, i));}

         res.push_back(v);
    }
return res;
}

int binomialCoeff(int n, int k)
{
    int res = 1;
    if (k > n - k)
    k = n - k;
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}




