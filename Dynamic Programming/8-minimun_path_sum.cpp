/*
PROBLEM STATEMENT: 
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Why a Greedy Solution doesn’t work?

As we have to return the minimum path sum, the first approach that comes to our mind is to take a greedy approach and always 
form a path by locally choosing the cheaper option.
We can clearly see the problem with the greedy solution. Whenever we are making a local choice, we may tend to choose a path 
that may cost us way more later.
Therefore, the other alternative left to us is to generate all the possible paths and see which is the path with the minimum 
path sum. To generate all paths we will use recursion.

Step 1: Express the problem in terms of indexes.
Base Case:

There will be three base cases:
When i=0 and j=0, that is we have reached the destination so we can add to path the current cell value, hence we return mat[0][0].
When i<0 or j<0, it means that we have crossed the boundary of the matrix and we don’t want to find a path from here, so we return 
a very large number( say, 1e9) so that this path is rejected by the calling function.
Step 2: Try out all possible choices at a given index.
    As we are writing a top-down recursion, at every index we have two choices, one to go up(↑) and the other to go left(←). To go upwards, 
    we will reduce i by 1, and move towards left we will reduce j by 1.
    Now when we get our answer for the recursive call (f(i-1,j) or f(i,j-1)), we need to also add the current cell value to it as we have to 
    include it too for the current path sum.

Step 3:  Take the maximum of all choices

As we have to find the minimum path sum of all the possible unique paths, we will return the minimum of the choices(up and left) 

Steps to memoize a recursive solution:

If we draw the recursion tree, we will see that there are overlapping subproblems. In order to convert a recursive solution the following steps will be taken:

Create a dp array of size [n][m]
Whenever we want to find the answer of a particular row and column (say f(i,j)), we first check whether the answer is already calculated using the dp 
array(i.e dp[i][j]!= -1 ). If yes, simply return the value from the dp array.
If not, then we are finding the answer for the given values for the first time, we will use the recursive relation as usual but before returning 
from the function, we will set dp[i][j] to the solution we get.


Steps to convert Recursive Solution to Tabulation one.

Tabulation is the bottom-up approach, which means we will go from the base case to the main problem.

The steps to convert to the tabular solution are given below:

Declare a dp[] array of size [n][m].
First initialize the base condition values, i.e dp[0][0] = matrix[0][0]
Our answer should get stored in dp[n-1][m-1]. We want to move from (0,0) to (n-1,m-1). But we can’t move arbitrarily, 
we should move such that at a particular i and j, we have all the values required to compute dp[i][j].
If we see the memoized code, values required for dp[i][j] are: dp[i-1][j] and dp[i][j-1]. So we only use the previous 
row and column value.
We have already filled the top-left corner (i=0 and j=0), if we move in any of the two following ways(given below), 
at every cell we do have all the previous values required to compute its value.
We can use two nested loops to have this traversal
Whenever i>0 , j>0, we will simply mark dp[i][j] = matric[i][j] + min(dp[i-1][j],dp[i][j-1]), according to our recursive relation.
When i=0 or j=0, we add to up( or left) 1e9, so that this path can be rejected.

Part 3: Space Optimization

If we closely look at the relation,

dp[i][j] = matrix[i][j] + min(dp[i-1][j] + dp[i][j-1]))

We see that we only need the previous row and column, in order to calculate dp[i][j]. Therefore we can space optimize it.

Initially, we can take a dummy row ( say prev) and initialize it as 0.

Now the current row(say temp) only needs the previous row value and the current row’s value in order to calculate dp[i][j].

At the next step, the temp array becomes the prev of the next step and using its values we can still calculate the next row’s values.
At last prev[n-1] will give us the required answer.
*/

//top-down- recusrion bases sol
class Solution {
public:
    int solve(int i, int j , vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(i == 0 and j == 0) return grid[0][0];
        if(i < 0 || j < 0) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];

        int up = grid[i][j] + solve(i -1, j, grid, dp);
        int left = grid[i][j] + solve(i, j-1, grid, dp);

        return dp[i][j] = min(up, left);


    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n , -1));

        return solve(m-1, n-1, grid, dp);

    }
};

//bottom-up-iteration
int minSumPath(int n, int m, vector<vector<int> > &matrix){
    vector<vector<int> > dp(n,vector<int>(m,0));
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) dp[i][j] = matrix[i][j];
            else{
                
                int up = matrix[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;
                
                int left = matrix[i][j];
                if(j>0) left+=dp[i][j-1];
                else left += 1e9;
                
                dp[i][j] = min(up,left);
            }
        }
    }
    
    return dp[n-1][m-1];
    
}

//STEP OPTIMIZED BOTTOM UP
int minSumPath(int n, int m, vector<vector<int> > &matrix){
      vector<int> prev(m,0);
    for(int i=0; i<n ; i++){
        vector<int> temp(m,0);
        for(int j=0; j<m; j++){
            if(i==0 && j==0) temp[j] = matrix[i][j];
            else{
                
                int up = matrix[i][j];
                if(i>0) up += prev[j];
                else up += 1e9;
                
                int left = matrix[i][j];
                if(j>0) left+=temp[j-1];
                else left += 1e9;
                
                temp[j] = min(up,left);
            }
        }
        prev=temp;
    }
    
    return prev[m-1];
    
}
