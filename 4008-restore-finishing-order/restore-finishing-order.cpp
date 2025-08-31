class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
    int n=order.size();
    map<int,int> mpp;
    for(auto it : friends) mpp[it]++;
    vector<int> ans;

    for(int i=0;i<n;i++){
        if(mpp.find(order[i])!=mpp.end()){
            ans.push_back(order[i]);
        }
    }
    return ans;
    }
};