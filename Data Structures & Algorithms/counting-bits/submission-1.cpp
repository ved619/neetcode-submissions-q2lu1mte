class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i=0;i<=n;++i){
            int num=i;
            int count=0;
            while(num!=0){
                if(num&1){
                    ++count;
                }
                num=num>>1;
            }
            result.push_back(count);
        }
        return result;
    }
};
