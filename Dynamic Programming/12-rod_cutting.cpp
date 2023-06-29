/*
PROBLEM STATEMENT: 
    Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. 
    Determine the maximum value obtainable by cutting up the rod and selling the pieces.
    Note: Consider 1-based indexing.

So here we are given a price array.
at any point we can either cut the rod or not, and the maximum prices we get is our answer
this is an example of UNBOUNDED KNAPSACK
how
    int knapsack we are given a sack of capacity W--here a rod of lenght N
    we are given a weight array of weight of our decision-- here we have to cut rod so lenght at which we cut
    we have a price of every decision--we have a price of every cut


*/

class Solution{
  public:
    int solve(int i, int price[], int n, vector<vector<int>>& dp)
    {
        int remain_lenght = n;
        if(i == 0)
        {
            //of lenght = 1;
            return n * price[0];
            
        }
        if(dp[i][n] != -1) return dp[i][n];
        int not_take = solve(i-1, price, n, dp);
        int take = 0;
        //want to cut a i + 1 piece
        if(n >= i+1)
        {
            take = price[i] + solve(i, price, n - i -1, dp);
            
        }
        return dp[i][n] = max(take, not_take);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return solve(n-1, price, n, dp);
    }
};
