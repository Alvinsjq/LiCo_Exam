/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (77.83%)
 * Likes:    1317
 * Dislikes: 0
 * Total Accepted:    309.5K
 * Total Submissions: 397.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    void backtrace(vector<int>& nums, vector<int>& onelist)
    {
        //结束条件 叶子节点处返回
        if(onelist.size() == nums.size())
        {
            res.push_back(onelist);
        }
        // 遍历所有可选项
        for(int i=0; i<nums.size(); i++)
        {
            // 前序做选择
            bool flag = false;
            for(int j=0; j<onelist.size(); j++)
            {   
                if(onelist[j] == nums[i])
                    flag = true;
            }
            if(flag) continue;
            onelist.push_back(nums[i]);
            backtrace(nums, onelist); // 遍历子节点
            // 后序还回选择
            onelist.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> onelist;
        backtrace(nums, onelist);
        return res;
    }

};
// @lc code=end

