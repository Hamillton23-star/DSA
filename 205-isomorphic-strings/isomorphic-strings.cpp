class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> map_s_t;
        unordered_map<char, char> map_t_s;

        for (int i = 0; i < s.size(); i++) {
            char sc = s[i];
            char tc = t[i];

            if (map_s_t.count(sc) && map_s_t[sc] != tc) return false;
            if (map_t_s.count(tc) && map_t_s[tc] != sc) return false;

            map_s_t[sc] = tc;
            map_t_s[tc] = sc;
        }

        return true;
    }
};
