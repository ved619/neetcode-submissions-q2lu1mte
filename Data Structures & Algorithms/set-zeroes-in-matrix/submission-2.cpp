class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> copyMatrix=matrix;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(copyMatrix[i][j]==0){
                    for(int x=0;x<m;++x){
                        matrix[i][x]=0;
                    }
                    for(int x=0;x<n;++x){
                        matrix[x][j]=0;
                    }
                }
            }
        }
    }
};
