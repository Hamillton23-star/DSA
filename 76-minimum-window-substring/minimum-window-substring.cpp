class Solution {
public:
    string minWindow(string s, string t) {
    int n=s.size();
    int m=t.size();
    vector<int> hash(256,0);
    for(auto it : t) hash[it]++;
    int l=0,r=0;
    int cnt=0;
    int si=-1;
    int minlen=1e9;
     while(r<n){
      if(hash[s[r]]>0)cnt++;
      hash[s[r]]--;

      while(cnt==m){
         if(r-l+1<minlen){
            minlen=r-l+1;
            si=l;
         }
         hash[s[l]]++;
         if(hash[s[l]]>0)cnt--;
         l++;
      }
    r++;
     }
     return  (si==-1) ? "": s.substr(si,minlen);
    }
};