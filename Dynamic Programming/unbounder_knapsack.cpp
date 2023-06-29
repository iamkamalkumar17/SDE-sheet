/*
A thief wants to rob a store. He is carrying a bag of capacity W. The store has ‘n’ items of infinite supply. 
Its weight is given by the ‘wt’ array and its value by the ‘val’ array. He can either include an item in its 
knapsack or exclude it but can’t partially have it as a fraction. We need to find the maximum value of items 
that the thief can steal. He can take a single item any number of times he wants and put it in his knapsack.

Why a Greedy Solution doesn’t work?
The first approach that comes to our mind is greedy. A greedy solution will fail in this problem because 
there is no ‘uniformity’ in data. While selecting a local better choice we may choose an item that will 
in long term give less value.

As the greedy approach doesn’t work, we will try to generate all possible combinations using recursion 
and select the combination which gives us the maximum value in the given constraints.

If ind==0, it means we are at the first item. Now, in an unbounded knapsack we can pick an item any number 
of times we want. As there is only one item left, we will pick for W/wt[0] times because we ultimately want 
to maximize the value of items while respecting the constraint of weight of the knapsack. The value added will 
be the product of the number of items picked and value of the individual item. Therefore we return (W/wt[0]) * val[0].

Exclude the current element in the subsequence: We first try to find a subsequence without considering the 
current index item. If we exclude the current item, the capacity of the bag will not be affected and the 
value added will be 0 for the current item. So we will call the recursive function f(ind-1,W)
Include the current element in the subsequence: We will try to find a subsequence by considering the current 
item to the knapsack. As we have included the item, the capacity of the knapsack will be updated to W-wt[ind] 
and the current item’s value (val[ind]) will also be added to the further recursive call answer.



*/

int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp){

    if(ind == 0){
        return ((int)(W/wt[0])) * val[0];
    }
    
    if(dp[ind][W]!=-1)
        return dp[ind][W];
        
    int notTaken = 0 + knapsackUtil(wt,val,ind-1,W,dp);
    
    int taken = INT_MIN;
    if(wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt,val,ind,W-wt[ind],dp);
        
    return dp[ind][W] = max(notTaken,taken);
}


int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
    
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return knapsackUtil(wt, val, n-1, W, dp);
}
