/*
Approach: Trie struct has 2 variables Node *links[26] (for storing characters); assuming all words have lowercase 
letters and a bool flag. The flag is always false except when the word ends.

Insert: The last reference trie’s flag has to be to true since the word is completed. The diagram shows the insertion of the word “apple”.

The basic idea of insertion is that if the reference trie does not exist create a new trie and if it does simply traverse to it.

Search: Search if the word is present in the trie or not,

Start from the root and traverse through the word. while traversing through the word check if the reference trie for that character exists 
or not. If it exists move to the reference trie, else return false. Once the word is traversed character by character return the flag at 
that particular trie.

startsWith: Check if the word inserted previously has the prefix “prefix” or not.

It is similar to a search operation. Start from the root of the trie and traverse through the “prefix”.If the reference trie for a 
character is not present return false else transverse to the reference trie.Once the “prefix’ is traversed completely character by character return true.
*/

struct Node {
	Node *links[26];
	bool flag = false;
	//checks if the reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	//setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
};

class Trie {
    private:
    Node* root;
public:

    Trie() {
		//creating new obejct
		root = new Node();
	}

	void insert(string word) {
		//initializing dummy node pointing to root initially
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
		}
		node->setEnd();
	}

	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}

	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	
    }
};
