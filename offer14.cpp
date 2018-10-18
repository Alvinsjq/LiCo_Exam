#include <iostream>

using namespace std;

class Solution{
public:
    int maxProductAfterCutting_dp(int length){
        if(length<2) return 0;
        if(length==2) return 1;
        if(length==3) return 2;
        int dp[length+1];
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 2;
        int max_ = 0;
        for(int i=4;i<=length;i++){
            max_ = 0;
            for(int j=1;j<=i;j++){
                int x = dp[j] * dp[i-j];
                if(x>max_)
                    max_ = x;
                dp[i] = max_; //将当前的max存入dp
            }
        }
        max_ = dp[length];
        delete[] dp;
        return max_;
    }

     int maxProductAfterCutting_greedy(int length){
        if(length<2) return 0;
        if(length==2) return 1;
        if(length==3) return 2;

        int time3 = length/3;
        if(length-time3 * 3 == 1)
            time3 --;

        int time2 = (length - time3 * 3)  / 2;
        return pow(3,time3) * pow(2,time2);

    }

};
