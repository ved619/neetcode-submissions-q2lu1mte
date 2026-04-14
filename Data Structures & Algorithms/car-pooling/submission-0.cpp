class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //step1: sort by starting point
        sort(trips.begin(),trips.end(),[](auto &a, auto &b){
            return a[1]<b[1];
        });
        //min-heap: {drop-location, number of passengers}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        int currentPassengers=0;

        for(auto &trip: trips){
            int passengers=trip[0];
            int from=trip[1];
            int to=trip[2];

            //step2: remove passengers who already got off
            while(!pq.empty() and pq.top().first<=from){
                currentPassengers-=pq.top().second;
                pq.pop();
            }
            currentPassengers+=passengers;
            if(currentPassengers>capacity){
                return false;
            }
            pq.push({to,passengers});
        }
        return true;
    }
};