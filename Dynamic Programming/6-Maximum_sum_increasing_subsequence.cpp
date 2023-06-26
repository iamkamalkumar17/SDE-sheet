/*
Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array 
such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence. 

again we will start pre from -1, so to represent it in dp we will do pre + 1, just as simple
*/

class Solution{
		

	public:
	int solve(int ind, int pre, int n, int arr[], vector<vector<int>>& dp)
	{
	    if(ind == n) return 0;
	    
	    if(dp[ind][pre + 1] != -1) return dp[ind][pre+1];
	    
	    int not_take = 0 + solve(ind+1, pre, n, arr, dp);
	    
	    int take = 0;
	    
	    if(pre == -1 || arr[ind] > arr[pre])
	    {
	        take = arr[ind] + solve(ind+1, ind, n, arr, dp);
	    }
	    
	    return dp[ind][pre + 1] = max(take, not_take);
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>>dp(n, vector<int>(n+1, -1));
	    return solve(0, -1, n, arr, dp);
	}  
};
