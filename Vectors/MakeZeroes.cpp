/*
Given a two-dimensional array, if any element within is zero, make its whole row and column zero. For example, consider the matrix below.
Input Format
In the function a 2d vector is passed.
Output Format
Return the updated 2d vector.
Sample Input
{ {5, 4, 3, 9}, {2, 0, 7, 6}, {1, 3, 4, 0}, {9, 8, 3, 4} }
Sample Output
{ {5, 0, 3, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {9, 0, 3, 0} }
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> makeZeroes(vector<vector<int>> arr){
    vector<int> row, col;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            if(arr[i][j]==0){
                row.push_back(i);
                col.push_back(j);
            }
        }
    }
    for(auto x: row){
        for(int i=0;i<arr.size();i++){
            arr[x][i]=0;
        }
    }
    for(auto x: col){
        for(int i=0;i<arr.size();i++){
            arr[i][x]=0;
        }
    }
    return arr;
}
