/*
You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.
A row i is weaker than a row j if one of the following is true:
The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
Input Format:
Integer m,n, matrix mat and k are passed in the function.
Output Format:
Return the vector as required.
Constraints:
m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] is either 0 or 1.

Sample Input
m = 4
n = 4
[[1,0,0,0],
[1,1,1,1],
[1,0,0,0],
[1,0,0,0]],
k = 2
Sample Output
[0,2]

Explanation
weakness of the rows is in the order- 0, 2, 3, 1
*/

#include<bits/stdc++.h>
using namespace std;


vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; //Min-heap
        for(int i=0;i<mat.size();i++)
        {
            int count=0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1)
                {
                    count++; //Counting the number of soldiers in each case
                }
            }
            pq.push(make_pair(count,i));
        }
        vector<int> x;
        while(k>0)
        {
            pair<int,int> temp=pq.top();
            x.push_back(temp.second);
            pq.pop();
            k--;
        }
        return x;
    }
