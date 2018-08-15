#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	//初始化最大值
    	vector<int> dp(nums.size());
        int max_ = nums[0];
        dp[0] = nums[0];
        //这里设f(k)为以k结尾的子串的最大的和，这个结果有两种情况
        //1. 以k-1位置结尾的子串与当前索引为k的值的和
        //2. 仅需要当前k索引下的数值
        //注意由于f(k)是以k结尾的，所以必须算上k索引的数值
        for(int i=1;i<nums.size();i++){
        	dp[i] = max(nums[i] + dp[i-1], nums[i]);
        	if(dp[i] > max_)
                max_ = dp[i];
        }
        return max_;
    }
};