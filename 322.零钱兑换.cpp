/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode-cn.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (42.75%)
 * Likes:    1234
 * Dislikes: 0
 * Total Accepted:    219.4K
 * Total Submissions: 507.5K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给定不同面额的硬币 coins 和一个总金额
 * amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 * 
 * 你可以认为每种硬币的数量是无限的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3 
 * 解释：11 = 5 + 5 + 1
 * 
 * 示例 2：
 * 
 * 
 * 输入：coins = [2], amount = 3
 * 输出：-1
 * 
 * 示例 3：
 * 
 * 
 * 输入：coins = [1], amount = 0
 * 输出：0
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：coins = [1], amount = 1
 * 输出：1
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：coins = [1], amount = 2
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 0 
 * 
 * 解题思路：
 * 状态转移
 * dp(n) = 
 * -1   n<0
 * 0    n=0
 * min{1+dp(n-coin)|coin belong coins} n>0
 * 
 */

// @lc code=start
class Solution {
public:
    /**
     * 自底向上完善db table
     * index  0  1  2  3  4  5  6  7  8  9  10 11
     * dp_int 12 12 12 12 12 12 12 12 12 12 12 12
     * dp     0  1  1  2  2  1  2  2  3  3  2  3
     */
    int coinChange(vector<int>& coins, int amount) {
        // 初始值为amount+1的原因是 最多使用全是面值为1的零钱
        int max_val = amount+1;
        vector<int> dp(amount+1, max_val);
        dp[0] = 0;
        for(int i=0; i<dp.size(); i++)
        {
            for(int j=0; j<coins.size(); j++)
            {
                if(i-coins[j] < 0) continue;
                dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
            }
        }
        return (dp[amount] == max_val) ? -1 : dp[amount];
    }
};
// @lc code=end

