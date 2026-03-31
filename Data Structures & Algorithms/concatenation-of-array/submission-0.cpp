class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n*2,0);
        for(int i=0;i<n;++i){
            result[i]=nums[i];
        }
        int a=0;
        for(int i=nums.size();i<result.size();++i){
            result[i]=nums[a];
            ++a;
        }
        return result;
    }
};