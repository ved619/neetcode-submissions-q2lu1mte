class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        //count frequency
        for(char t: tasks){
            freq[t-'A']++;
        }
        //max heap
        priority_queue<int> pq;
        for(int f: freq){
            if(f>0){
                pq.push(f);
            }
        }
        int time=0;
        while(!pq.empty()){
            int cycle=n+1;
            vector<int> temp;
            int workDone=0;
            //try to fill the cycle
            while(cycle-- and !pq.empty()){
                int curr=pq.top();
                pq.pop();
                curr--;
                workDone++;
                if(curr>0){
                    temp.push_back(curr);
                }
            }
            //push remaining tasks back into the heap
            for(int t: temp){
                pq.push(t);
            }
            //if heap is empty -> no idle needed
            if(pq.empty()){
                time+=workDone;
            }
            else{
                time+=(n+1);
            }
        }
        return time;
    }
};
