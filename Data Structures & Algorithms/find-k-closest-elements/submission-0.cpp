class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i=0,j=arr.size()-1;
        while(j-i+1>k){
            if(abs(arr[i]-x) > abs(arr[j]-x)){
                ++i;
            }
            else{
                --j;
            }
        }
        vector<int> result;
        for(int a=i;a<=j;++a){
            result.push_back(arr[a]);
        }
        return result;
    }
};