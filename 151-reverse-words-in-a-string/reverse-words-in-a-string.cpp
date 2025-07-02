class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string> st;
        string word = "";
        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (!word.empty()) {
                st.push(word);
                word = "";
            }
        }  
        if (!word.empty()) st.push(word); 
        
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
            if (!st.empty()) result += ' ';
        }
        return result;
    }
};
