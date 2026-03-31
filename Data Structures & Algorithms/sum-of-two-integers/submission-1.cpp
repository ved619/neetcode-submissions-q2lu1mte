class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int partialSum=a^b;
            int carry=a&b;
            carry=carry<<1;
            a=partialSum;
            b=carry;
        }
        return a;
    }
};
