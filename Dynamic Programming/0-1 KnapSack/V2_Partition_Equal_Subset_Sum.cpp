/*
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

if the sum of the array is odd the it can't be divided into two equal partitions. so we return false;

in this question, we don't have the option to leave, either we put in first partition or the second.
theoretically there are three values that are changing here, n, sum1, and sum2.
  but we think deeper we can see that sum2 is associated with sum1. so we can consider only two variables n and sum1

since we have to partition in half, so if we can take form a subset that will give half sum, then the left ones will automatically form the subset that
will give the other half. so we can reduce the problem in 0-1 knapsack
pick a subset with sum = sumArray/2;


for tabulation
  the question is converted into subset sum problem and we can easily make the table of that problem
  one thing we need to note,
    when we say that if(j< arr[i-1] so we can't take that element into out account, we are not actually leaving that
      because in that very row we are going to go for various number of j, and we will apply arr[i-1] in all those scenerios.
        so if we get some point where we can afford it, we will take it
*/


class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        long long sum = 0;
        int n = N;
        for(int i =0; i<n; i++ ) {
            sum+=arr[i];
        }
        
        if(sum % 2 != 0) return false;
        sum/=2;
        
        int t[n+1][sum+1];
        for(int i = 0; i<=n; i++) {
            for(int j =0; j<= sum; j++) {
                if(i == 0) t[i][j] = 0;
                if(j == 0) t[i][j] = 1;
            }
        }
        
        for(int i = 1; i<= n; i++) {
            for(int j = 1; j<=sum; j++ ) {
                if(j >= arr[i-1]) {
                    t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
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
    int solve(int n, int arr[], long long sum, vector<vector<int>>& dp) {
        if(n == 0) {
            if(sum == 0) return true;
            return false;
        }
        if(dp[n][sum] != -1) return dp[n][sum];
        int first = solve(n-1, arr, sum - arr[n-1], dp);
        int second = solve(n-1, arr, sum, dp);
        if(first) return dp[n][sum] = first;
        return dp[n][sum] = second;
    }
    int equalPartition(int N, int arr[])
    {
        long long sum = 0;
        int n = N;
        for(int i =0; i<n; i++ ) {
            sum+=arr[i];
        }
        
        if(sum % 2 != 0) return false;
        sum/=2;
        
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return solve(n, arr, sum, dp);
        
    }
};
