class Solution {
public:
    bool canFinish(int speed, vector<int>& piles, int h){
        int timeTaken=0;
        for(int i=0;i<piles.size();++i){
            if(piles[i]>speed){
                if(piles[i]%speed==0){
                    timeTaken+=piles[i]/speed;
                }
                else{
                    timeTaken+=piles[i]/speed + 1;
                }
            }
            else{
                timeTaken+=1;
            }
        }
        return timeTaken<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=INT_MIN;
        for(int pile:piles){
            right=max(right,pile);
        }
        int ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(canFinish(mid,piles,h)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};
