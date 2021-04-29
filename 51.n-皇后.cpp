/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (73.81%)
 * Likes:    855
 * Dislikes: 0
 * Total Accepted:    120.8K
 * Total Submissions: 163.6K
 * Testcase Example:  '4'
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 * 
 * 
 * 
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[["Q"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> result;

    bool isValid(int row, int col, vector<string> square)
    {
        // 横向无需确认
        // 纵向
        for(int i=0; i<row; i++)
        {
            if(square[i][col] == 'Q')
            {
                return false;
            }
        }

        // 左上
        for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--)
        {
            if(square[i][j] == 'Q')
            {
                return false;
            }
        }

        // 右上            
        for(int i=row-1,j=col+1; i>=0 && j<=square.size(); i--,j++)
        {
            if(square[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }

    void backtrace(int row, vector<string> square)
    {
        // 终止条件
        if(row == square.size())
        {   
            result.push_back(square);
            return;
        }

        for(int col=0; col<square.size(); col++)
        {
            // 选择可以放Q的位置
            if(!isValid(row, col, square)) continue;
            // 此处填Q
            square[row][col] = 'Q';
            // 回溯
            backtrace(row+1, square);
            // 恢复原值
            square[row][col] = '.';
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> square(n, string(n, '.'));
        backtrace(0, square);
        return result;
    }
};
// @lc code=end

