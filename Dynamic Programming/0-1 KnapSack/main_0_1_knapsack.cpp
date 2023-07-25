/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the 
maximum total value in the knapsack. Note that we have only one quantity of each item.
You cannot break an item, either pick the complete item or dont pick it (0-1 property).


*/

//identify: 
//1.choices: in dynamic problem question we are given choices and we need to make decision based on those choices
//              like in this question we have the choices for each item, that whether we want to put it into the bag or not
//2.optimal: in dp, we are often asked to give give us something optimal, like max or min values ets
//				like in this question we are asked to find the maximum value that we can get


//for every dp question we follow this sequence: recusion -> memoization -> top-down(tabulation)

/*
A. RECUSTION
		base condition: what we are doing is that we start from last element and keep reducing our sample space (n)
  					so when we reach n(arrays size() ) == 0, we have no sample size so we return 0;
	   				also we are picking item in bag and reducing w(capacity), so when we reach w = 0, we end the recursion branch and retur 0

  		now for every item we have two scenerio, either its wt is less that w, in that case we have the option to take it
				so when wt[n-1] <= w, then
						we can either take it or not and return maximum value among both scenerio
	  						return max(val[n-1] + solve(wt, val, w-wt[n-1], n-1), solve(wt, val, w, n-1));
		 		else we have only one option and that is to not take it
	 					return dp[n][w] = solve(wt, val, w, n-1);

	the recursive approach is correct and given enough time, will give correct output. but in constraint time, it will give TLE for bigger inputs					
*/

/*
B: MEMOIZATION
	the recursive approach will give tle because branch may become deeper. but we may get repeating branches.
 	dp help us deal with it smartly, when we get repeating branch, it does not traverse the whole branch again, but use the result of the branch that it has 
  	already traversed. and doing so it saves time.
   	so by definition we need to store information of every branch that we traverse.
	we do it using matrixed generally.	
 		here among all the inputs in the recursion we have only two inputs that change with every call, W and n
   		so what we do is make a matrix that can store every possible value of w and n that we can encounter and in case they repeat we have a easy way out
         so we make matrix of dp[n+1][w+1] and we initialize it with -1 stating it does not have any value currently
        we keep encoutering values and we keep storing them in dp
        Note: we can also do this with dp[n][w] and it will work just fine, we do it this way to reduce confusion during implementaion

    if we declare the matrix globally we do not need to carry in our recusion call as input, that simplies a lot of things
    we can initiaze a array matrix with -1 with memeset function
        memset(dp, -1, sizeof(dp));

    DISADVANTAGES: one possible disadvantage of memoization is that is can fully occupy stack and we may get stack overflow, although it is very rare
            but it is a possiblity
            tabulation will never give any such result         
*/

/*
C. TOP-DOWN
    in this method we just convert the recusive method in iterative method.
    we make the same table like in memoization
    base contion: 
        in recursion 
            if(n == 0 || w == 0) {
                return 0;
            }
        here also, whenever we encounter n = 0 or w = 0, we just put zero in it 

    we have made table t[n][w];
    what every cell of our table mean
        t[i][j]=> means that if we have only i elements in our rows from stating and our capacity is j, then the answer is t[i][j];
            cleary t[n][w] is our answer, and anytime i = 0 or j = 0 our answer is 0;
        at i, we solve it with j as cap.
            we check if our j can accomodate our corresponding wt ,ie, wt[i-1] (indexing)
            if we can, then we have two option either to take it or not.
                t[i][j] = max(val[i-1] + t[i-1][j - wt[i-1]], t[i-1][j]);
            this translates to, corresponding val + val when only i-1 elemnt were there and max capacity was t-current wt
            or we can just not take it, that will not change our val any bit so it will be our val when i-1 elements were their

    this makes so much sence now/.
    
*/

class Solution
{
    public:
    int dp[1001][1001];
    //Function to return max value that can be put in knapsack of capacity W.

    int solve(int wt[], int val[], int w, int n) {
        if(n == 0 || w == 0) {
            return 0;
        }
        if(dp[n][w] != -1) return dp[n][w];
        if(wt[n-1] <= w) {
            return dp[n][w] = max(val[n-1] + solve(wt, val, w-wt[n-1], n-1), solve(wt, val, w, n-1));
        }
        else {
            return dp[n][w] = solve(wt, val, w, n-1);
        }
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   int t[n+1][W+1];
    //   //this fill -1 at all places in table
    //   memset(dp, -1, sizeof(dp));
    //   return solve(wt, val, W, n);
       
       int t[n+1][W+1];
       //base condition->initialization
       for(int i = 0; i<n+1; i++) {
           for(int j = 0; j<W+1 ; j++) {
               if(i == 0 || j == 0) {
                   t[i][j] = 0;
               }
           }
       }
       
       for(int i = 1 ; i < n+1; i++ ) {
           for(int j = 1; j<W+1; j++) {
               if(wt[i-1] <= j) {
                    t[i][j] = max(val[i-1] + t[i-1][j - wt[i-1]], t[i-1][j]);
               }
               else {
                   t[i][j] = t[i-1][j];
               }
           }
       }
       return t[n][W];
    }
};
