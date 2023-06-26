/*
A thief wants to rob a store. He is carrying a bag of capacity W. The store has ‘n’ items. Its weight is given by the ‘wt’ array and 
its value by the ‘val’ array. He can either include an item in its knapsack or exclude it but can’t partially have it as a fraction. 
We need to find the maximum value of items that the thief can steal.

Why a Greedy Solution doesn’t work?

The first approach that comes to our mind is greedy. A greedy solution will fail in this problem because there is no ‘uniformity’ in 
data. While selecting a local better choice we may choose an item that will in long term give less value.

As the greedy approach doesn’t work, we will try to generate all possible combinations using recursion and select the combination which 
gives us the maximum value in the given constraints.

Step 1: Express the problem in terms of indexes.
Step 2: Try out all possible choices at a given index.
    Exclude the current element in the subsequence: We first try to find a subsequence without considering the current index item. 
    If we exclude the current item, the capacity of the bag will not be affected and the value added will be 0 for the current item. 
    So we will call the recursive function f(ind-1,W)
    
    Include the current element in the subsequence: We will try to find a subsequence by considering the current item to the knapsack. 
    As we have included the item, the capacity of the knapsack will be updated to W-wt[ind] and the current item’s value (val[ind] will 
    also be added to the further recursive call answer. We will make a recursive call to f(ind-1, W- wt[ind]).



momoisation: Create a dp array of size [n][W+1]. The size of the input array is ‘N’, so the index will always lie between ‘0’ and ‘n-1’. 
The capacity can take any value between ‘0’ and ‘W’. Therefore we take the dp array as dp[n][W+1]
*/
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int ind, int wt[], int val[], int w, vector<vector<int>> &dp)
    {
        if(ind == 0) 
        {
            if(wt[0] <= w) return val[0];
            else return 0;
        }
        if(dp[ind][w] != -1) return dp[ind][w];
        
        int not_take = solve(ind-1, wt, val, w, dp);
        int take = INT_MIN;
        if(wt[ind] <= w)
        {
            take = val[ind] + solve(ind-1, wt, val, w-wt[ind], dp);
        }
        return dp[ind][w] = max(take, not_take);
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n, vector<int>(W+1, -1));
       
       return solve(n-1, wt, val, W, dp);
       
       
    }
};
