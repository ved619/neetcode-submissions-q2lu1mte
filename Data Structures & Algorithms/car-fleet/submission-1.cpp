class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,double>> cars;
        //step1: compute time
        for (int i = 0; i < n; i++) {
            double t = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], t});
        }
        //step2: sort by position
        sort(cars.begin(),cars.end());
        stack<double> st;
        //step3: process from right
        for(int i=n-1;i>=0;--i){
            double currTime=cars[i].second;
            if(st.empty() or currTime> st.top()){
                st.push(currTime);
            }
        }
        return st.size();
    }
};
