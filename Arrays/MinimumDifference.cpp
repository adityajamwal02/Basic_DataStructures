/*
Implement a function that takes in two non-empty arrays of integers, finds the pair of numbers (one from each array) who absolute difference is closest to zero, and returns a pair containing these two numbers, with the first number from array. Only one such pair will exist for the test.

Input

Array1 = [23, 5, 10, 17, 30]
Array2 = [26, 134, 135, 14, 19]
Output

17,19
*/

///Brute force

#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;


pair<int,int> minDifference(vector<int> a,vector<int> b){
    int minimum=INT_MAX;
    int min1=0, min2=0;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            int diff=abs(a[i]-b[j]);
            if(diff<minimum){
                minimum=diff;
                min1=a[i];
                min2=b[j];
            }
        }
    }
    return {min1,min2};
}


/// Binary Search

#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


pair<int,int> minDifference(vector<int> a1,vector<int> a2){
    //Complete this method
    // Write your code here.
	sort(a2.begin(),a2.end());
	vector<int> result;
	//iterate over 1 and do binary search
	int p1,p2;

	int diff = INT_MAX;

	for(int x : a1){
			auto lb = lower_bound(a2.begin(),a2.end(),x) - a2.begin();

			if(lb>=1 and x - a2[lb-1] < diff){
					diff = x - a2[lb-1];
				  p2 = a2[lb-1];
				  p1 = x;
			}

		 if(lb!=a2.size() and a2[lb]-x < diff ){
			 		diff = a2[lb] - x;
			 		p1 = x;
			 		p2 = a2[lb];
		 }
	}

  return {p1,p2};
}
