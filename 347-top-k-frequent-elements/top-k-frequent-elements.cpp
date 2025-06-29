class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        vector<vector<int>> bucket(n + 1); 
        for (auto it: freqMap) {
            int num=it.first;
            int freq=it.second;
            bucket[freq].push_back(num);
        }

        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; --i) {
            for (int num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};
