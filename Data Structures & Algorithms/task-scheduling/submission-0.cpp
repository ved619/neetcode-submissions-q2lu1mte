class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);

        // step 1: count frequencies
        for(char t: tasks){
            freq[t-'A']++;
        }
        //step 2: max heap
        priority_queue<int> pq;
        for(int f: freq){
            if(f>0){
                pq.push(f);
            }
        }
        //step 3: cooldown queue
        queue<pair<int,int>> cooldown;
        int time=0;
        while(!pq.empty() or !cooldown.empty()){
            time++;
            //step4: Execute task if available
            if(!pq.empty()){
                int curr=pq.top();
                pq.pop();
                curr--;
                if(curr>0){
                    cooldown.push({curr,time+n});
                }
            }
            //step 5: check cooldown
            if(!cooldown.empty() and cooldown.front().second==time){
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }
        return time;
    }
};
