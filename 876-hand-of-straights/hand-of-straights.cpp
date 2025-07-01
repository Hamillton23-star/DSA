class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        map<int,int> mpp;
        for(int num: hand) mpp[num]++;
        priority_queue<int , vector<int> , greater<int>> pq;
        for(auto it: mpp){
            int card=it.first;
            pq.push(card);
        }
        while(!pq.empty()){
            int start=pq.top();
            for(int i=0; i< groupSize;i++){
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