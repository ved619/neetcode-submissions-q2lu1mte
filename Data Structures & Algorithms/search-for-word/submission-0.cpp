class Solution {
public:
    vector<vector<bool>> isVisited;
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    int n,m;
    bool ans=false;

    bool isValid(int row, int col){
        if(row<0 or row>=n or col<0 or col>=m){
            return false;
        }
        if(isVisited[row][col]){
            return false;
        }
        return true;
    }
    void backTrack(int row, int col, vector<vector<char>>& board, const string& word,int index){
        if(ans){
            return;
        }
        if(board[row][col]!=word[index]){
            return;
        }   
        if(index==word.length()-1){
            ans=true;
            return;
        }
        isVisited[row][col]=true;

        for(int i=0;i<4;++i){
            int nr=row+dr[i];
            int nc=col+dc[i];

            if(isValid(nr,nc) and board[nr][nc] == word[index+1]){
                backTrack(nr,nc,board,word,index+1);
            }
        }
        isVisited[row][col]=false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();

        isVisited.assign(n,vector<bool>(m,false));
        ans=false;
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]==word[0]){
                    backTrack(i,j,board,word,0);
                    if(ans){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
