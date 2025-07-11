class Solution {
public:
    int myAtoi(string s) {
       int n=s.size();
       int i=0;
       while(i<n && s[i]==' ')i++;
       int sign=1;
       if(i<n && (s[i]=='+' || s[i]=='-')) {
        sign= (s[i]=='-') ? -1: 1;
        i++;
       } 
       long long num=0;
       while(i<n && isdigit(s[i])){
        num=num*10+(s[i]-'0');
         if(sign==1 && sign*num >= INT_MAX)return INT_MAX;
         if(sign==-1 && sign*num <= INT_MIN)return INT_MIN;
          i++;
       }
      return sign*num;
    }
};