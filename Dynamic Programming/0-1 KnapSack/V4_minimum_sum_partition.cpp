/*
Given an array arr of size n containing non-negative integers, the task is to divide it into 
two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference
*/

class Solution{

  public:
  
    int solve(int n, int arr[], int sum1, int sum2, int& ans, vector<vector<int>>& dp) {
        if(n == 0 ) {
            ans = min(ans, abs(sum1-sum2));
            return ans;
        }
        if(dp[n][sum1] != -1) return dp[n][sum1];
        int first = solve(n-1, arr, sum1 + arr[n-1], sum2, ans, dp);
        int second = solve(n-1, arr, sum1, sum2+arr[n-1], ans, dp);
        return dp[n][sum1] = min(first, second);
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum1 = 0;
	    int sum2= 0;
	    int ans = INT_MAX;
	    int sum = 0;
	    for(int i = 0; i<n; i++ ) {
	        sum+=arr[i];
	    }
	    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
	    return solve(n, arr, sum1, sum2, ans, dp);
	} 
};
