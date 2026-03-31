class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //brute force
        int n=temperatures.size();
        vector<int> result(n,0);
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                if(temperatures[j]>temperatures[i]){
                    result[i]=j-i;
                    break;
                }
            }
        }
        return result;
    }
};
