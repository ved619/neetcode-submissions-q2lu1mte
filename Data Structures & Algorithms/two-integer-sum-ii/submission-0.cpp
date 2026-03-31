class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int l=0,r=n-1;
        vector<int> result;
        while(l<r){
            int sum=numbers[l]+numbers[r];
            if(sum==target){
                result.push_back(l+1);
                result.push_back(r+1);
                break;
            }
            else if(target<sum){
                --r;
            }
            else{
                ++l;
            }
        }
        return result;
    }
};
