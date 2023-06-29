/*
PROBLEM STATEMENT:
    Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of 
    the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.

this question is similar to mcm

for a certain string we make cuts everywhere. if we get a palindrome anywhere then we make a cut and find out cuts in left and right
then we compare this scenerio with others
*/

class Solution{
public:

    //to check palindrome
    bool isPal(string &s, int i, int j)
    {
        while(i<j)
        {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s, int i, int j, vector<vector<int>>& dp)
    {
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(isPal(s, i, j)) return 0;
        int ans = INT_MAX;
        for(int k = i; k<j; k++)
        {
            if(isPal(s, i, k))
            {
                if(dp[i][k] == -1)
                {
                    dp[i][k] = solve(s, i, k, dp);
                }
                
                if(dp[k+1][j] ==-1)
                {
                    dp[k+1][j] = solve(s, k+1, j, dp);
                }
                
                int temp = dp[i][k] + dp[k+1][j] + 1;
                ans = min(ans, temp);
            }
            
            
        }
        return dp[i][j] = ans;
    }
    
    int palindromicPartition(string str)
    {
        // code here
        int n = str.length();
        int i =0; 
        int j =n-1;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(str, i, j, dp);
    }
};
