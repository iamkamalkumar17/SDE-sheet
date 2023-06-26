/*
PROBLEM STATEMENT
      Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the 
      one that involves the least number of multiplications.
      
      The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the 
      ith matrix has the dimensions (arr[i-1] x arr[i]).

PATTERN : PARTITION DP
    Pattern Identification:
        Whenever we need to find the answer to a large problem such that the problem can be broken into subproblems 
        and the final answer varies due to the order in which the subproblems are solved, we can think in terms of partition DP.

Rules to solve the problem of partition DP:
    1.Start with the entire block/array and mark it with i,j. We need to find the value of f(i,j).
    2.Try all partitions.
    3.Run the best possible answer of the two partitions ( answer that comes after dividing the problem into two subproblems and solving them recursively).

STEPS TO MEMOIZE THE CODE
        As there are overlapping subproblems in the recursive tree, we can memoize the recursive code to reduce the time complexity.
        
        1.Create a dp array of size [n][n]. I and j can range from 0 to n-1 so we take the size n X n.
        2.We initialize the dp array to -1.
        3.Whenever we want to find the answer to particular parameters (say f(i,j)), we first check whether the answer is 
          already calculated using the dp array(i.e dp[i][j]!= -1 ). If yes, simply return the value from the dp array.
        4.If not, then we are finding the answer for the given value for the first time, we will use the recursive relation 
          as usual but before returning from the function, we will set dp[i][j] to the solution we get.
          
*/


//recurssively-->it will give us TLE
class Solution{
public:
    int solve(int arr[], int i, int j)
    {
        if(i == j) return 0;
        int mini = INT_MAX;
        for(int k = i; k<=j-1; k++)
        {
            int ans = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]* arr[k] * arr[j];
            mini = min(mini, ans);
        }
        return mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int i = 1;
        int n = N-1;
        return solve(arr, i, n);
    }
};


//optimised--dp--accepted
class Solution{
public:
    int solve(int arr[], int i, int j, vector<vector<int>>& dp)
    {
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k = i; k<=j-1; k++)
        {
            int ans = solve(arr, i, k,dp) + solve(arr, k+1, j,dp) + arr[i-1]* arr[k] * arr[j];
            mini = min(mini, ans);
        }
        return dp[i][j] =mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int i = 1;
        int n = N-1;
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return solve(arr, i, n,dp);
    }
};
