#include <iostream>

using namespace std;

bool invalidInput = false;

class Solution {
public:
    double Power(double base, int exponent) {
        invalidInput = false;
        if(base == 0.0 && exponent < 0){
            invalidInput = true;
            return 0.0;
        }
        unsigned int absexponent = (unsigned int) (exponent);
        if(exponent < 0)
            absexponent = (unsigned int) (-exponent);

        double res = PowerWithUnsign(base, absexponent);
        if(exponent < 0)
            res = 1.0/res;
        return res;
    }

    double PowerWithUnsign(double base, int exponent){
        if(exponent == 0)
            return 1;
        if(exponent == 1)
            return base;
        double result = PowerWithUnsign(base,exponent>>1);//右移1位代表除以2
        result *= result;
        if(exponent & 0x1 ==1) //位运算代替求余数
            result *= base;
        return result;
    }
};


int main(){

    Solution s;
    cout<<s.Power(2,3)<<endl;

    return 0;
}
