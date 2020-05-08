/*
 * @Author: your name
 * @Date: 2020-04-24 15:31:08
 * @LastEditTime: 2020-05-08 09:39:09
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \ezlab-docd:\Sublime_WorkSPace\Lico\LiCo_Exam\621.task-scheduler.cpp
 */
/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (46.17%)
 * Total Accepted:    145.9K
 * Total Submissions: 304.8K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * Given a char array representing tasks CPU need to do. It contains capital
 * letters A to Z where different letters represent different tasks. Tasks
 * could be done without original order. Each task could be done in one
 * interval. For each interval, CPU could finish one task or just be idle.
 * 
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle.
 * 
 * You need to return the least number of intervals the CPU will take to finish
 * all the given tasks.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 * 
 * 桶思想
 * 1\ 最大频率的任务其频率为maxFreq
 * 2、最大的时间不超过 maxFreq × (n + 1);
 * 3\ 有可能最大频率的任务不止一个任务，记有p个最大频率的任务，那么这种情况可以往前推一个，最大为
       R = (maxFreq-1) * (n+1) + p
 * 4、如果冷却时间短，任务数很多，计算得到的R要小于task数量，说明maxFreq以内是填满了，剩下的任务需要继续耗时，
   此时取task数量
 */
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int array_size[26]{}; // 存放对应任务的数量
        int tasks_length = 0; // 任务的种数
        // 统计对应任务的数量
        for(vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
            array_size[(*it) - 'A']++;
        // 获取任务种类个数
        int max_freq = 0;  // 求最大频率
        for(int i=0; i<26; i++)
        {
            if(array_size[i] > 0){
                tasks_length++;
                if(array_size[i] > max_freq)
                max_freq = array_size[i];
            }
        }
       // 求拥有最大频率的数量
       int q = 0;
       for(int i=0; i<26; i++)
           if(array_size[i] == max_freq)
               q++;
               
       int R = (max_freq - 1) * (n + 1) + q;
       return R > tasks_length ? R : tasks_length;
    }
};
