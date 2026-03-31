class Solution {
public:
    int n,m;
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    bool ans=false;
    bool isValid(int row,int col, vector<vector<bool>>& isVis){
        if(row<0 or row>=n or col<0 or col>=m){
            return false;
        }
        if(isVis[row][col]){
            return false;
        }
        return true;
    }
    void backTrack(int row,int col, const string& word, int index,  vector<vector<char>>& board, vector<vector<bool>>& isVis){
        if(ans){
            return;
        }
        if(board[row][col]!=word[index]){
            return;
        }
        if(index==word.size()-1){
            ans=true;
            return;
        }
        isVis[row][col]=true;
        for(int i=0;i<4;++i){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(isValid(nr,nc,isVis) and board[nr][nc]==word[index+1]){
                backTrack(nr,nc,word,index+1,board,isVis);
            }
        }
        isVis[row][col]=false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        vector<vector<bool>> isVis(n,vector<bool>(m,false));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]==word[0]){
                   if(!ans){
                        backTrack(i,j,word,0,board,isVis);
                   }
                }
            }
        }
        return ans;
    }
};
