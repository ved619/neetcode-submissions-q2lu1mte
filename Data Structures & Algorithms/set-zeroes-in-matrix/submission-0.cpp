class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return;
        }
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> copy=matrix;

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(matrix[i][j]==0){
                    for(int col=0;col<m;++col){
                        copy[i][col]=0;
                    }
                    for(int row=0;row<n;++row){
                        copy[row][j]=0;
                    }
                }
            }
        }
        matrix.swap(copy);
    }
};
