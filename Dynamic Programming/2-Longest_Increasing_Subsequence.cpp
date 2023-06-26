/*
first stop is what is subsequence
subseqeunce : A subsequence of an array is a list of elements of the array where some elements are deleted ( or not deleted at all) 
and they should be in the same order in the subsequence as in the original array.
For example, for the array: [2,3,1] , the subsequences will be [{2},{3},{1},{2,3},{2,1},{3,1},{2,3,1}} but {3,2} is not a subsequence 
because its elements are not in the same order as the original array.

What is the Longest Increasing Subsequence?
The longest increasing subsequence is described as a subsequence of an array where:
    All elements of the subsequence are in increasing order.
    This subsequence itself is of the longest length possible.

Approach 1: Using Brute Force

We are given an array arr[]. To find the longest increasing subsequence, the brute force method that comes to our mind is to 
generate all subsequences and then manually filter the subsequences whose elements come in increasing order and then return the longest such subsequence. 
This naive approach will give us the correct answer but to generate all the subsequences, we will require exponential ( 2n ) time. 
Therefore we will try some other approaches.

Approach 2: Using Dynamic Programming

Step 1: Express the problem in terms of indexes.
Step 2: Explore all possibilities at a given index
      Do not consider the current element in the subsequence: In this case, we are not considering the current element in the subsequence, 
      therefore the length of the subsequence will not increase and the prev_index element will remain as it is. 
      Hence we will return 0 + f(ind+1,prev_index) as our answer.

      Consider the current element in the subsequence: In this case, we are considering the current element in the subsequence, 
      therefore the length of the subsequence will increase by 1 and the prev_index element will be updated to the current index element.. 
      Hence we will return 1 + f(ind+1,ind) as our answer. Here is a simple catch, when we want to consider the current index element to the 
      subsequence, we need to check that it is greater than the last element of the subsequence so far,i.e the prev_index element.

      Note: When prev_index is -1, it means that we have not considered any element to our subsequence. Therefore, we can always consider 
      the current element (arr[ind]) for our subsequence.

Step 3:  Return the maximum of the choices
                                f(ind, prev_index){
                                
                                    if(ind == n)
                                        return 0
                                
                                    notTake = 0 + f(ind + 1, prev_index)
                                
                                    if(prev_index == -1 || arr[ind]>arr[prev_index]){
                                        take = 1 + f(ind + 1, ind)
                                    }
                                
                                    return max(notTake, take)
                                }
                                
Steps to memoize a recursive solution:

As we see there are overlapping subproblems in the recursive tree, we can memorize the recursive code to reduce the time complexity.
Our function has two variables that are changing: ind and prev_ind.
‘ind’ represents the index of the array. It can range from 0 to n-1.
‘prev_index’ also represents the index of the array. When we have not considered any element in our LIS, prev_index is -1. 
Therefore, prev_index can range from -1 to n-1. Now we cannot store the -1 index in our 2D array. Therefore, we would do a coordinate shift of one.


*/

class Solution {
public:
    //the range of prev_ind is from -1 to n-1, as when we have not taken any element
    //we want prev_ind to be -1
    //but we can represent -1 as index of array so we do a coordinate shift
    //so range of prev_ind is from 0 to n
    //ans that is the reason for all the prev_ind + 1 thingyes
    int solve(vector<int>& nums, int n, int ind, int prev_ind, vector<vector<int>>& dp)
    {
        if(ind == n) return 0;
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];

        int not_take = 0 + solve(nums, n, ind+1, prev_ind, dp);
        int take = 0;
        if(prev_ind == -1 || nums[ind] > nums[prev_ind])
        {
            take = 1 + solve(nums, n, ind+1, ind, dp);
        }
        dp[ind][prev_ind+1] = max(take, not_take);
        return max(take, not_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n =nums.size();

        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return solve(nums, n, 0, -1, dp);


    }
};
