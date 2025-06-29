class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mpp;
        for(int num: nums)mpp[num]++;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        for(auto it: mpp){
            int freq=it.second;
            int ele=it.first;
            pq.push({freq,ele});
           if(pq.size()>k)pq.pop();
        }
        vector<int> ans;
       while(!pq.empty()){
        auto pt=pq.top();
        int elem=pt.second;
        ans.push_back(elem);   
         pq.pop();     
       }
       return ans;
    }
};