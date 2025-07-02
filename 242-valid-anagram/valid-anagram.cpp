class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mpp1;
           map<char,int> mpp2;
        for(char cp: s)mpp2[cp]++;
        for(char ct : t)mpp1[ct]++;
       
      return (mpp1==mpp2);
    }
};