/*
Given a palindromic string of lowercase English letters palindrome, replace exactly one character with any lowercase English letter so that the resulting string is not a palindrome and that it is the lexicographically smallest one possible.
Return the resulting string. If there is no way to replace a character to make it not a palindrome, return an empty string.

Example-1
Input: palindrome = "abccba"
Output: "aaccba"
Explanation: There are many ways to make "abccba" not a palindrome, such as "zbccba", "aaccba", and "abacba".
Of all the ways, "aaccba" is the lexicographically smallest.

Example-2
Input: palindrome = "a"
Output: ""
Explanation: There is no way to replace a single character to make "a" not a palindrome, so return an empty string.

Example-3
Input: palindrome = "aa"
Output: "ab"

Example-4
Input: palindrome = "aba"
Output: "abb"
*/

#include<bits/stdc++.h>
using namespace std;

    string breakPalindrome(string palindrome) {
	//If we have string size == 1, return "". Since any replacement cannot break the palindrome.
        if(palindrome.size() == 1)
            return "";

        vector<vector<int>> count(26);
        int firstNonA = -1;

        for(int i = 0; i < palindrome.size(); i++)
        {
            count[palindrome[i] - 'a'].push_back(i);

            //Update firstNonA index if its not yet found.
            if(firstNonA == -1 && palindrome[i] != 'a')
                firstNonA = i;
        }

        //If we have N-1 a's, we need to replace last a with b
        if(count[0].size() >= palindrome.size() - 1)
            palindrome[count[0].back()] = 'b';
        //Else replace first non-'a' character with 'a'
        else
            palindrome[firstNonA] = 'a';

        return palindrome;
    }
