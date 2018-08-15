#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
       
        return backtrack(0, 0, m, n);


		//memoization
		// int mat[m+1][n+1];
		// for(int i=0;i<m+1;i++)
		// 	for(int j=0;j<n+1;j++)
		// 		mat[i][j] = -1;

		// return backtrack(0,0,m,n,mat);
    }


private:
	//top-down
	int backtrack(int r, int c, int m, int n){
		if(r == m-1 && c == n-1)
			return 1;
		if(r >=m || c >= n)
			return 0;
		return backtrack(r+1, c, m, n) + backtrack(r, c+1, m, n);
	}

	//memoization
	// int backtrack(int r, int c, int m, int n, int **mat){
	// 	if(r == m-1 && c == n-1)
	// 		return 1;
	// 	if(r >=m || c >= n)
	// 		return 0;
	// 	if(mat[r+1][c] == -1)
	// 		mat[r+1][c] = backtrack(r+1, c, m, n, mat);
	// 	if(mat[r][c+1] == -1)
	// 		mat[r][c+1] = backtrack(r, c+1, m, n, mat);	}
	// 	return mat[r+1][c] + mat[r][c+1];

	//down-top 
	int downtop(int m, int n){
		vector<vector<int>> mat(m+1, vector<int>(n+1));//注意这里是如何定义二维vector的
		mat[m-1][n] = 1;
		for(int r = m-1; r>=0; r--)
			for(int c = n-1; c>=0; c--)
				mat[r][c] = mat[r+1][c] + mat[r][c+1];
		return mat[0][0];
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