struct Node {
    Node* links[2];
    
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }
    
    Node* get(int bit) {
        return links[bit];
    }
    
    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMaxXor(int num) {
        Node* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxXor |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        
        vector<tuple<int, int, int>> offlineQueries;
        for (int i = 0; i < queries.size(); i++) {
            offlineQueries.push_back({queries[i][1], queries[i][0], i}); // {m, x, idx}
        }
        sort(offlineQueries.begin(), offlineQueries.end());

        Trie trie;
        vector<int> ans(queries.size());
        int i = 0, n = nums.size();

        for (auto& [m, x, idx] : offlineQueries) {
           
            while (i < n && nums[i] <= m) {
                trie.insert(nums[i]);
                i++;
            }
            if (i == 0) {
                ans[idx] = -1;  
            } else {
                ans[idx] = trie.getMaxXor(x);
            }
        }

        return ans;
    }
};
