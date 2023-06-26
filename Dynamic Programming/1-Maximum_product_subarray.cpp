//Given an array that contains both negative and positive integers, find the maximum product subarray.


class Solution {
public:
    int maxProduct(vector<int>& nums) {

        //kadane's (O)N

        int prod1 = nums[0];
        int prod2 = nums[0];
        int result = nums[0];
        for(int i =1; i<nums.size(); i++)
        {
            int temp = max({nums[i], prod1*nums[i], prod2*nums[i]});
            
            prod2 = min({nums[i], prod1*nums[i], prod2*nums[i]});
            prod1 = temp;

            result = max(result, prod1);
        }
        return result;
        // //O(N) accepted
        // int n = nums.size();
        // int maxleft = INT_MIN;
        // int maxright = INT_MIN;
        // int prod = 1;
        // bool zero = false;
        // for(int i =0; i<n; i++)
        // {
        //     prod = prod * nums[i];
        //     if(nums[i] == 0)
        //     {
        //         zero = true;
        //         prod = 1;
        //         continue;
        //     }
        //     maxleft = max(maxleft, prod);
        // }
        // prod = 1;
        // for(int i = n-1; i>=0; i--)
        // {
        //     prod = prod * nums[i];
        //     if(nums[i] == 0)
        //     {
        //         zero = true;
        //         prod = 1;
        //         continue;
        //     }
        //     maxright = max(maxright, prod);
        // }
        // if(zero == true) return max( max(maxright, maxleft), 0);
        // return max(maxright, maxleft);

        // //O(N) but still tle
        // int n = nums.size();
        // int ans = INT_MIN;
        // for(int i =0; i<n; i++)
        // {
        //     int prod = nums[i];
        //     for(int j = i + 1; j<n; j++)
        //     {
        //         ans = max(prod, ans);
        //         prod *=nums[j];
        //     }
        //     ans = max(ans, prod);
        // }
        // return ans;
        //O(N^3) correct but tle
        // int ans = INT_MIN;
        // int n = nums.size();
        // for(int i =0; i<n; i++)
        // {
        //     for(int j =i ; j<n; j++)
        //     {
        //         int prod = 1;
        //         for(int k = i; k<=j; k++)
        //         {
        //             prod = prod * nums[k];
        //         }
        //         ans = max(ans, prod);
        //     }
        // }
        // return ans;

    }
};


/*
this is very similar to the " max cumulative sum subarray" problem. here you keep 2 values: the max cumulative product UP TO current element starting from SOMEWHERE in the past, and the minimum cumuliative product UP TO current element . it would be easier to see the DP structure if we store these 2 values for each index, like maxProduct[i],minProduct[i] .

at each new element, u could either add the new element to the existing product, or start fresh the product from current index (wipe out previous results), hence the 2 Math.max() lines.

if we see a negative number, the "candidate" for max should instead become the previous min product, because a bigger number multiplied by negative becomes smaller, hence the swap()

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // store the result that is the max we have found so far
        int ans = nums[0];

        // imax/imin stores the max/min product of
        // subarray that ends with the current number A[i]
        int imax = ans;
        int imin = ans;

        for(int i = 1; i<nums.size(); i++)
        {
            // multiplied by a negative makes big number smaller, small number bigger
            // so we redefine the extremums by swapping them

            if(nums[i] < 0)swap(imax, imin);
            
                
            // max/min product for the current number is either the current number itself
            // or the max/min by the previous number times the current one
            imax  = max(nums[i], imax*nums[i]);
            imin = min(nums[i], imin*nums[i]);

            // the newly computed max value is a candidate for our global result
            ans = max(ans, imax);
            
        }
        return ans;
    }
};
*/
