/*
Given a string, find all the possible subsequences of the string.Solution 1: Using bit manipulation
Approach: Prerequisites: To check whether the ith bit is set or not.If n&(1<<i) != 0,then the ith bit is set.
First, write down all the numbers from 0 to 2^(n)-1 and their bit representation.0 means I am not picking the 
character in my subsequence, and 1 means I am picking the character.

Basically, we traverse from 0 to 2^(n)-1 and check for every number if their bit is set or not. 
If the bit is set add that character to your subsequence.
*/

//bit manupulation
vector<string> AllPossibleStrings(string s) {
	int n = s.length();
	vector<string>ans;
	for (int num = 0; num < (1 << n); num++) {
		string sub = "";
		for (int i = 0; i < n; i++) {
			//check if the ith bit is set or not
			if (num & (1 << i)) {
				sub += s[i];
			}
		}
		if (sub.length() > 0) {
			ans.push_back(sub);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

//simple recusrions solution
class Solution{
	public:
	    void solve(int i, string s, vector<string> &ans, string dum)
	    {
	        if(i == s.size())
	        {
	            if(dum!="") ans.push_back(dum);
	            return;
	        }
	        //take
	        dum+=s[i];
	        solve(i+1, s, ans, dum);
	        dum.pop_back();
	        solve(i+1, s, ans, dum);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n = s.size();
		    vector<string> ans;
		    string dum = "";
		    solve(0, s, ans, dum);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
		
};
