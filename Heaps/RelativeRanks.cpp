/*
You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.
The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:
The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.
Input Format:
An array score[] is passed in the given function.
Output Format:
Return an array of ranks of all athletes.

Constraints:
n == score.length
1 <= n <= 10^4
0 <= score[i] <= 10^6
All the values in score are unique.

Sample Test Cases:
Input 1:
score = [5,4,3,2,1]
Output 1:
["Gold Medal","Silver Medal","Bronze Medal","4","5"]
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
    int n=score.size();
    priority_queue<pair<int, int>> pq;
    for(int i=0;i<n;i++){
        pq.push({score[i],i});
    }
    vector<string> result(n);
    int count=0;
    while(!pq.empty()){
        count++;
        if(count==1){
            result[pq.top().second].append("Gold Medal");
        }else if(count==2){
             result[pq.top().second].append("Silver Medal");
        }else if(count==3){
             result[pq.top().second].append("Bronze Medal");
        }else{
            result[pq.top().second].append(to_string(count));
        }
    pq.pop();
    }
return result;
}
