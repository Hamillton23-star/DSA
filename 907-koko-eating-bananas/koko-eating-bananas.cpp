class Solution {
public:
    int calculateh(vector<int>& piles, int k) {
        long long cnt = 0; 
        for (int i = 0; i < piles.size(); i++) {
            cnt += (piles[i] + k - 1) / k;  
        }
        return cnt;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (calculateh(piles, mid) <= h) {
                right = mid; 
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
