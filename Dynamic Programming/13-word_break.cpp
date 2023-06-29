/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

what we will do is we will move through the string and find if till certain i it exist in dictionary.
if it does then we call the function back from next index
*/

class Solution {
public:
    bool solve(int i, string s, set<string>& st, vector<int>& dp)
    {
        if(i == s.size()) return true;
        if(dp[i] != -1) return dp[i];
        string temp;
        for(int ind = i; ind<s.size(); ind++)
        {
            temp+=s[ind];
            if(st.find(temp) != st.end())
            {
                if(solve(ind+1, s, st,dp)) return true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        vector<int> dp(s.size() + 1, -1);
        for(int i = 0; i<wordDict.size(); i++)
        {
            st.insert(wordDict[i]);
        }
        return solve(0, s, st,dp);
    }
};
