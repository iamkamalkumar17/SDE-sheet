/*
Given a string of length N of lowercase alphabet characters. The task is to complete the 
function countDistinctSubstring(), which returns the count of total number of distinct substrings of this string.


Intuition:

The basic intuition is to generate all the substrings and store them in the trie along with its creation. If a 
substring already exists in the trie then we can ignore, else we can make an entry and increase the count. 

The 1st step is to create the trie structure and it generally consists of an array of nodes. Since we are going 
to have only alphabetic characters in the string, the maximum size of the array will be 26. We can also extend 
to accommodate upper case letters, if we want.
Then, we are going to generate all substrings of the given string. It can be done by 2 nested loops. For each 
iteration, the outer loop fixes the starting point and the inner loop traverses the substring from the starting 
point to the end of the string.
For each character encountered in the traversal of the inner loop, we are checking whether that particular node 
in the trie already contains the character or not. 
If it has, it means that the currently generated substring is a duplicate one. And we can just go to the next 
iteration to check the next character. But if the current character is not in the current node, then it means 
that the current substring generated is a brand new one.

And we are creating a new node for the latest character. Since it is a new substring, we are increasing the total count.
Since, the problem also demands to include empty string, we can just add 1(for empty string) to the total counts we got earlier..

*/

struct Node{
    Node* links[26];
    
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void put(char ch, Node* node)
    {
        links[ch-'a'] = node;
    }
    
};

int countDistinctSubstring(string s)
{
    Node* root = new Node();
    int count = 0;
    int n=s.size();
    for(int i=0; i<n; i++)
    {
        Node* node = root;
        for(int j = i; j< n; j++)
        {
            if(node->containsKey(s[j]) == false)
            {
                node->put(s[j], new Node());
                count++;
            }
            node = node->get(s[j]);
        }
    }
    return count + 1;
}
