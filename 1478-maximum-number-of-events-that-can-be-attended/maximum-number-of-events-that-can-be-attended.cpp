class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
     sort(events.begin(),events.end());

     priority_queue<int , vector<int> , greater<int>> pq;
     int day=1,i=0;
     int count=0;
     while(!pq.empty() || i<n){

        while(i<n && events[i][0]==day){
            pq.push(events[i][1]);
            i++;
        }
     

     while(!pq.empty() && pq.top()<day){
            pq.pop();
     }

     if(!pq.empty()){    
        pq.pop();
        count++;
      }
      day++;
     }
     return count;
    }

};