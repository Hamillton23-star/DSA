class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& y) {
        int n=y.size();
        stack<int> st;
        vector<int> nge(n,0);

        for(int i=0;i<n;i++){
            while(!st.empty() && y[i]>y[st.top()]){
                int ind=st.top();
                st.pop();
                nge[ind]=i-ind;
            }
            st.push(i);
        }
        return nge;
    }
};