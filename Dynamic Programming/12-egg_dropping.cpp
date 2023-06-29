//aditya verma taught this one
/*
PROBLEM STATEMENT: 
    You are given N identical eggs and you have access to a K-floored building from 1 to K.
    There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher 
    than f will break, and any egg dropped at or below floor f will not break.
    Return the minimum number of moves that you need to determine with certainty what the value of f is.

this question is very similar to mcm
we don't know which floor should we choose to throw egg, so we through egg from each floor and see which will take minimum attempts

if egg break: then our threshold floor is below given floor, so floor = k and also we loose and egg so egg--;
if egg does not break : then our threshold floor is above this floor or this floor itself, so floor = floor - k;
*/

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    //we are return number of attempts in this recusive call
    int solve(int egg, int floor, vector<vector<int>>&dp)
    {
        //if we have only only floor then we can find out ans in only on attemp
        if(floor == 1 || floor == 0) return floor;
        
        //if we have only one egg, then we have to start from bottom and keep throwing
        //so no.of attempts = floor
        if(egg == 1) return floor;
        
        if(dp[egg][floor] != -1) return dp[egg][floor];
        int mini = INT_MAX;
        
        for(int k = 1; k<=floor; k++)
        {
            int breaky = solve(egg-1, k-1, dp);
            int not_break = solve(egg, floor - k, dp);
            //since we have to find worst case scenerio so we use this max function
            int ans = 1 + max(breaky, not_break);
            mini = min(mini, ans);
        }
        return dp[egg][floor] =mini;
        
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
        int i = 1;
        int j = k;
        return solve(n, k,dp);
        
    }
};
