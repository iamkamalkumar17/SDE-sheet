/*
A subsequence of a string is a list of characters of the string where some characters are deleted ( or not deleted at all) 
and they should be in the same order in the subsequence as in the original string.

Note: For a string of length n, the number of subsequences will be 2^n.

Approach 1: Using Brute Force
We are given two strings, S1, and S2 (suppose of same length n), the simplest approach will be to generate all the 
subsequences and store them, then manually find out the longest common subsequence.
This naive approach will give us the correct answer but to generate all the subsequences, we will require 
exponential ( 2n ) time. Therefore we will try some other approaches.

Approach 2: Using Dynamic Programming
Step 1: Express the problem in terms of indexes.
    A single variable can’t express both the strings at the same time, 
    so we will use two variables ind1 and ind2. They mean that we are considering string S1 from index 0 ind1 and string S2 
    from index 0 to S2. 

Step 2: Explore all possibilities at a given index
    if(S1[ind1] == S2[ind2]) as in the figure below. In this case this common element will represent a unit length common 
    subsequence, so we can say that we have found one character and we can shrink both the strings by 1 to find the longest 
    common subsequence in the remaining pair of strings.

    if(S1[ind1] != S2[ind2]) as in the figure given below. In this case we know that the current characters represented by 
    ind1 and ind 2 will be different. So, we need to compare the ind1 character with shrunk S2 and ind2 with shrunk S1. 
    But how do we make this comparison ?  If we make a single recursive call as we did above to f(ind1-1,ind2-1), we may 
    lose some characters of the subsequence. Therefore we make two recursive calls: one to f(ind1,ind2-1) (shrinking only S1) 
    and one to f(ind1-1,ind2) (shrinking only S2). Then when we return max of both the calls.
    

*/

class Solution {
public:

    int solve(string & s1, string& s2, int ind1, int ind2, vector<vector<int>> &dp)
    {
        if(ind1 < 0 || ind2 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2])
        {
            return dp[ind1][ind2] = 1 + solve(s1, s2, ind1-1, ind2-1,dp);
        }
        else 
            return dp[ind1][ind2] =max(solve(s1, s2, ind1, ind2-1,dp), solve(s1, s2, ind1-1, ind2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return solve(text1, text2, n-1, m-1, dp);
    }
};
