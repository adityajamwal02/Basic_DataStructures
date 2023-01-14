/*
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).

Input Format:
Vector nums[] of integers is passed in the function.
Output Format:
Return a single integer as required.

Constraints:
2 <= nums.length <= 500
1 <= nums[i] <= 10^3
Sample Input
nums = [3,4,5,2]

Sample Output
12

Explanation
(nums[1]-1) * (nums[2]-1) = (4-1) * (5-1) = 12
*/

#include<bits/stdc++.h>
using namespace std;


int maxProduct(vector<int>& nums) {
    priority_queue<int> pq;
    for(auto i: nums){
        pq.push(i-1);
    }
    int ans=pq.top();
    pq.pop();

    return ans*pq.top();
}
