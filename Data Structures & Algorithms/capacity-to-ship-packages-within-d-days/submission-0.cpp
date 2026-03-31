class Solution {
public:

    bool canShipWithinDays(int capacity, vector<int>& weights, int days){
        int sum=0,timeTaken=1;
        for(int i=0;i<weights.size();++i){
            if(weights[i]+sum>capacity){
                timeTaken++;
                sum=0;
            }
            sum+=weights[i];
        }
        return timeTaken<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN;
        int high=0;
        for(int weight:weights){
            high+=weight;
            low=max(low,weight);
        }    
        int result=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canShipWithinDays(mid,weights,days)){
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
    }
};