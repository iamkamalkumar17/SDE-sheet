/*
PROBLEM STATEMENT:
      Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
      You have the following three operations permitted on a word:
              Insert a character
              Delete a character
              Replace a character


Step 1: Express the problem in terms of indexes.
Step 2: Try out all possible choices at a given index.
(i) When the characters match
          if(S1[i]==S2[j]) 
          If this is true, now as the characters at i and j match, we would not want to do any operations 
          to make them match, so we will just decrement both i and j by 1 and recursively find the answer 
          for the remaining string portion. We return 0+f(i-1,j-1).

(ii) When the characters don’t match

    if(S1[i] != S2[j]) is true, then we have to do any of three operations to match the characters. 
    We have three options, we will analyze each of them one by one.

    return 1+f(i-1,j) // Insertion of character.
    return 1+f(i,j-1) // Deletion of character.
    return 1+f(i-1,j-1) // Replacement of character.


Create a dp array of size [n][m]. The size of S1 and S2 are n and m respectively, so the variable i will always 
lie between ‘0’ and ‘n-1’ and the variable j between ‘0’ and ‘m-1’.

*/

//top-down approach

class Solution {
public:
    int solve(string s1, string s2, int i, int j , vector<vector<int>>& dp)
    {
        if(i<0) return j +1 ;
        if( j < 0) return i +1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return dp[i][j] = solve(s1, s2, i-1, j-1, dp);

        else return dp[i][j] =1+ min(solve(s1,s2,i-1,j-1,dp), min(solve(s1,s2, i, j-1,dp),   solve(s1,s2,i-1,j,dp)));
    }
    int minDistance(string word1, string word2) {



        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return solve(word1, word2, m-1, n-1, dp);

    }
};b    

//bottom - up approach
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i<=m; i++)
        {
            dp[i][0] = i;
        }
        for(int j = 1 ; j<=n; j++)
        {
            dp[0][j] = j;
        }
        for(int i =1; i<=m; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] =1+ min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1] ));
                }
            }
        }
        return dp[m][n];
    }
};
