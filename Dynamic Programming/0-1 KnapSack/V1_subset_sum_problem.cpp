/*
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

similarly to 01 knapsack, we have a list of items and we can either choose from them or not, but our sum should not exceed sumGiven.

we do minor changes in the code and we arrive in to the same result

here in tabulation:
  if(i == 0 ) that means we do not have any array element
      so if we have any sum > 0 then we can not produce a result-> hence 0
  if(j== 0) that means given sum is 0->so we can give an empty subset->hence 1


not for further calculation
  if(arr[i-1] <= j) that means we can take that element in our sum considaration
    so we have to see if it can go back to sum = 0, and we have to check value of t[i-1][j-arr[i-1]];

*/

class Solution{  
    // int subSetSum(int index,int sum,vector<vec)
public:
    int dp[101][10001];
    bool solve(vector<int> arr, int n, int sum)
    {
        //bc
        if(n == 0) {
            if(sum == 0) return true;
            return false;
        }
        if(dp[n][sum] != -1) return dp[n][sum];
        bool take = false;
        if(arr[n-1] <= sum) {
            take = solve(arr, n-1, sum-arr[n-1]);
        }
        bool not_take = false;
        not_take = solve(arr, n-1, sum);
        return  dp[n][sum] = take || not_take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        memset(dp, -1, sizeof(dp));
        
        return solve(arr, arr.size(), sum);
    }
};

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        int t[n+1][sum+1];
        
        for(int i = 0; i<=n; i++) {
            for(int j =0; j<=sum; j++) {
                if(i == 0) t[i][j] = 0;
                if(j == 0) t[i][j] = 1;
            }
        }
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=sum; j++) {
                if(j >= arr[i-1]) {
                    t[i][j] = (t[i-1][j-arr[i-1]]) || (t[i-1][j]);
                }
                else {
                t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
};
