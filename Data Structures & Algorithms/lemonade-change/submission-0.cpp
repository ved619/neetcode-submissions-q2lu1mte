class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> umap;
        umap[5]=0;
        umap[10]=0;
        for(int i=0;i<bills.size();++i){
            if(bills[i]==5){
                umap[5]++;
            }
            else if(bills[i]==10){
                if(umap[5]==0){
                    return false;
                }
                umap[5]--;
                umap[10]++;
            }
            else if(bills[i]==20){
                if(umap[5]>=3){
                    umap[5]=umap[5]-3;
                }
                else{
                    if(umap[5]==0 or umap[10]==0){
                        return false;
                    }
                    umap[5]--;
                    umap[10]--;
                }
            }
        }
        return true;
    }
};