class Solution {
public:
    bool doesExist(vector<int>& arr, int target){
        int l=0,r=arr.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==target){
                return true;
            }
            if(arr[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> flat;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                flat.push_back(matrix[i][j]);
            }
        }
        bool ans=doesExist(flat,target);
        return ans;
    }
};
