class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.size(), np = p.size();
        if (ns < np) return {};

        vector<int> pCount(26, 0), sCount(26, 0);
        vector<int> result;

        for (char c : p) pCount[c - 'a']++;
        for (int i = 0; i < np; ++i) sCount[s[i] - 'a']++;

        if (sCount == pCount) result.push_back(0);
        for (int i = np; i < ns; ++i) {
            sCount[s[i] - 'a']++;                       
            sCount[s[i - np] - 'a']--;                  
            if (sCount == pCount) result.push_back(i - np + 1); 
        }

        return result;
    }
};
