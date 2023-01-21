/*
Array Products
Implement a function that takes in a vector of integers, and returns a vector of the same length, where each element in the output array is equal to the product of every other number in the input array. Solve this problem without using division.
In other words, the value at output[i] is equal to the product of every number in the input array other than input[i]. You can assume that answer can be stored inside int datatype and no-overflow will occur due to products.

Sample Input
Both inputs and outputs are vectors.
{1,2,3,4,5}
Sample Output
{120, 60, 40, 30, 24}
*/


#include<vector>
using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){
    int n=arr.size();
    vector<int> output(n,1);
    if(n==1){
        return {0};
    }
    int temp=1;
    for(int i=0;i<n;i++){
        output[i]=temp;
        temp*=arr[i];
    }
    temp=1;
    for(int i=n-1;i>=0;i--){
        output[i]*=temp;
        temp*=arr[i];
    }
    return output;
}
