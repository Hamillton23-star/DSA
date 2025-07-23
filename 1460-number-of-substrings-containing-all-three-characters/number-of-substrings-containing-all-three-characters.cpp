class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        map<char,int>mpp;
        int cnt=0;
        int l=0;
        int r=0;
        while(r<n){
            mpp[s[r]]++;
            while(mpp['a']>0 && mpp['b']>0 && mpp['c']>0){
                cnt+=n-r;
                mpp[s[l]]--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};