class Solution {
public:
    const int MOD = 1e9 + 7;
    long long countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, long long> cntY;
        for (auto &p : points) {
            cntY[p[1]]++;
        }

        long long linesSeen = 0;
        long long sumComb = 0;   
        long long result = 0;

        for (auto &kv : cntY) {
            long long k = kv.second;
            if (k < 2) continue;

            long long c2 = k * (k - 1) / 2;  
            result = (result + (sumComb * c2) % MOD) % MOD;
           

            sumComb += c2;
            linesSeen++;
        }

        return result;
    }
};
