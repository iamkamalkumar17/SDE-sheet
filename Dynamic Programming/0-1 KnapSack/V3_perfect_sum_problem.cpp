/*
Given an array arr[] of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7

this is also similar to subset sum problem, but with variation that we need to calculate the number of subsets that will give certains um
again we have two option to either pick or not pick a certain element
  we will calculate how many subsets are their with picking option, and how many are their with not picking option
    tabulated solution is more visualized, but recusive one can be seen as an induction problem where we assume that take and not take will gives us
    the total number of subsets with their scenerio and we just add them


    
*/

class Solution{

	public:
	int mod = (int)1e9+7;
	
	int perfectSum(int arr[], int n, int sum)
	{
        int t[n+1][sum+1];
        
        for(int i = 0; i<=n; i++ ) {
            for(int j = 0; j<=sum; j++ ) {
                if(i == 0) t[i][j] = 0;
                if(j == 0) t[i][j] = 1;
            }
        }
        for(int i = 1; i<= n; i++ ) {
            for(int j = 0; j<=sum; j++ ) {
                if(j >= arr[i-1]) {
                    t[i][j] = (t[i-1][j] + t[i-1][j-arr[i-1]])%mod;
                }
                else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
	}
	  
};



class Solution{

	public:
	int mod = (int)1e9+7;
	int solve(int n, int arr[], int sum, vector<vector<int>>& dp) {
	    if(n == 0) {
	        if(sum == 0) return 1;
	        return 0;
	    }
	    if(dp[n][sum] != -1) return dp[n][sum];
	    //take
	    int take = 0;
	    if(arr[n-1] <= sum) take = solve(n-1, arr, sum-arr[n-1], dp);
	    //not take
	    int not_take = solve(n-1, arr, sum, dp);
	    return dp[n][sum] = (take + not_take)% mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        
        return solve(n, arr, sum, dp);
       
	}
	  
};
