class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
         int n=nums.size();
        map<int,int> mpp;
        for(int num: nums) mpp[num]++;
        priority_queue<int , vector<int> , greater<int>> pq;
        for(auto it: mpp){
            int card=it.first;
            pq.push(card);
        }
        while(!pq.empty()){
            int start=pq.top();
            for(int i=0; i<k;i++){
                int elem=start+i;
                if(mpp[elem]==0)return false;
                mpp[elem]--;
                if(mpp[elem]==0 && elem==pq.top()){
                    pq.pop();
                }
            }
        }
        return true;
    }
};