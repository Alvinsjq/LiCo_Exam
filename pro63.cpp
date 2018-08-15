#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
    	vector<vector<int>> path(m,vector<int>(n));
    	//设置边界条件
    	if(obstacleGrid[0][0]!=1)
    		path[0][0] = 1;
    	else 
    		path[0][0] = 0;
    	for(int i=1;i<m;i++)
    		if(obstacleGrid[i][0] == 1)
    			path[i][0] = 0;
    		else
    			path[i][0] = path[i-1][0];
    	for(int j=1;j<n;j++)
    		if(obstacleGrid[0][j] == 1)
    			path[0][j] = 0;
    		else
    			path[0][j] = path[0][j-1];

    	//设置状态函数
    	for(int i=1;i<m;i++)
    		for(int j=1;j<n;j++)
    			path[i][j] = obstacleGrid[i][j] == 1 ? 0 : path[i - 1][j] + path[i][j - 1];

    	return path[m-1][n-1];
    }



};


// https://leetcode.com/problems/unique-paths/discuss/22954/0ms-5-lines-DP-Solution-in-C++-with-Explanations
class Solution {
    int uniquePaths(int m, int n) {
        vector<vector<int> > path(m, vector<int> (n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                path[i][j] = path[i - 1][j] + path[i][j - 1];
        return path[m - 1][n - 1];
    }
};