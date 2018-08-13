#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> v;
        int m = matrix.size();
        if(m == 0)
        	return v;
        int n = matrix[0].size();
        int row = 0, col = -1;
        while(true){

        	//up
        	for(int i=0;i<n;i++)
        		v.push_back(matrix[row][++col]);

        	if(--m == 0) break;// 已经是最后一行了
        	//right
        	for(int i=0;i<m;i++)
        		v.push_back(matrix[++row][col]);

        	if(--n == 0) break;//已经是最后一列了
        	//down
        	for(int i=0;i<n;i++)
        		v.push_back(matrix[row][--col]);

        	if(--m == 0) break;// 已经是最后一行了
        	//left
        	for (int i = 0; i < m; i++)
        		v.push_back(matrix[--row][col]);

        	if(--n == 0) break;//已经是最后一列了

        }
        return v;
    }
};