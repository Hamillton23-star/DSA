struct Node{
	Node* links[2];
};

class Trie {
	private: Node *root = new Node();
	public:

	Trie() {
		root = new Node();
	}

	void insert(int num) {
		Node *node = root;
		for (auto i=31;i>=0;i--) {
			int bit = (num >> i) & 1;
			if(node->links[bit] == NULL) {
				Node *temp = new Node();
				node->links[bit] = temp;
			}
			node = node->links[bit];
		}
	}

	int maxXor(int num) {
		Node *node = root;
		int ans=0;
		for (auto i=31;i>=0;i--) {
			int bit = (num >> i) & 1;
			if(node->links[!bit] != NULL) {
				ans = ans | (1 << i);
				node = node->links[!bit];
			}
			else node = node->links[bit];
		}
		return ans;
	}
};

class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		Trie trie;
		int fans=0;
		for (auto i:nums) trie.insert(i);

		for (auto i:nums) fans = max(fans, trie.maxXor(i));
		return fans;
	}
};