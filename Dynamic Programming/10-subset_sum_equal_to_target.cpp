/*
PROBLEM: We are given an array ‘ARR’ with N positive integers. We need to find if there is a subset in “ARR” with 
a sum equal to K. If there is, return true else return false.

Why a Greedy Solution doesn’t work?
A Greedy Solution doesn’t make sense because we are not looking to optimize anything. We can rather try to generate 
all subsequences using recursion and whenever we get a single subsequence whose sum is equal to the given target, we can return true.

Step 1: Express the problem in terms of indexes.
Base Cases:

If target == 0, it means that we have already found the subsequence from the previous steps, so we can return true.
If ind==0, it means we are at the first element, so we need to return arr[ind]==target. If the element is equal to 
the target we return true else false.

Step 2: Try out all possible choices at a given index.
Exclude the current element in the subsequence: We first try to find a subsequence without considering the current index element.
For this, we will make a recursive call to f(ind-1,target).
Include the current element in the subsequence: We will try to find a subsequence by considering the current index as element 
as part of subsequence. As we have included arr[ind], the updated target which we need to find in the rest if the array will 
be target – arr[ind]. Therefore, we will call f(ind-1,target-arr[ind]).


Step 3:  Return (taken || notTaken)

As we are looking for only one subset, if any of the one among taken or not taken returns true, we can return true from our 
function. Therefore, we return ‘or(||)’ of both of them.


Steps to memoize a recursive solution:

If we draw the recursion tree, we will see that there are overlapping subproblems. In order to convert a recursive solution the following steps will be taken:

Create a dp array of size [n][k+1]. The size of the input array is ‘n’, so the index will always lie between ‘0’ and ‘n-1’. The target can take any value 
between ‘0’ and ‘k’. Therefore we take the dp array as dp[n][k+1]
We initialize the dp array to -1.
Whenever we want to find the answer of particular parameters (say f(ind,target)), we first check whether the answer is already calculated using the dp 
array(i.e dp[ind][target]!= -1 ). If yes, simply return the value from the dp array.
If not, then we are finding the answer for the given value for the first time, we will use the recursive relation as usual but before returning from 
the function, we will set dp[ind][target] to the solution we get.

Steps to convert Recursive Solution to Tabulation one.

To convert the memoization approach to a tabulation one, create a dp array with the same size as done in memoization. We can set its type 
as bool and initialize it as false.

First, we need to initialize the base conditions of the recursive solution.

If target == 0, ind can take any value from 0 to n-1, therefore we need to set the value of the first column as true.
The first row dp[0][] indicates that only the first element of the array is considered, therefore for the target value equal to arr[0], only cell 
with that target will be true, so explicitly set dp[0][arr[0]] =true, (dp[0][arr[0]] means that we are considering the first element of the array 
with the target equal to the first element itself). Please note that it can happen that arr[0]>target, so we first check it: if(arr[0]<=target) 
then set dp[0][arr[0]] = true.


*/


bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target==0)
        return true;
    
    if(ind == 0)
        return arr[0] == target;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    bool notTaken = subsetSumUtil(ind-1,target,arr,dp);
    
    bool taken = false;
    if(arr[ind]<=target)
        taken = subsetSumUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken||taken;
}

bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    
    return subsetSumUtil(n-1,k,arr,dp);
}


bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    
    if(arr[0]<=k)
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][k];
}
