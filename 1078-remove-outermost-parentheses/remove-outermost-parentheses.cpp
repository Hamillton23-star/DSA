class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int cnt1=0;
        string ans="";
        int start=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') cnt1++;
            if(s[i]==')') cnt1--;
            if(cnt1==0){
             ans+=s.substr(start+1,i-start-1);
             start=i+1;
            }
        }
        return ans;
    }
};