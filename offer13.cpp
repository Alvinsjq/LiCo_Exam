#include <string.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols){
        if(rows<1 || cols <1)
            return 0;
        int num = 0;
        bool* visited = new bool[rows * cols];
        memset(visited,0,rows * cols);
        haspath(threshold,rows,cols,0,0,visited);

        //最后遍历一遍格子中标记为true的格子数量即为最终机器人能够到达的格子数
        for(int row = 0; row < rows; row++)
            for(int col=0; col < cols; col++)
                if(visited[row  * cols + col])
                    num ++;

        return num;
    }

    void haspath(int threshold, int rows, int cols, int row, int col, bool* visited){
        //开始标记，首先设置边界
        if(row>=0 && row<rows && col>=0 && col<cols && !visited[row * cols + col]){
            //计算不能进入的格子
            int bitsum = getBitSum(row) + getBitSum(col);
            if(bitsum <= threshold){
                //只有在能进入的格子中才能够进行递归，在递归中进行标记
                visited[row * cols + col] = true;
                haspath(threshold,rows,cols,row-1,col,visited);
                haspath(threshold,rows,cols,row+1,col,visited);
                haspath(threshold,rows,cols,row,col-1,visited);
                haspath(threshold,rows,cols,row,col+1,visited);
            }
        }
    }

private:
    int getBitSum(int x){
        int sum = 0;
        while(x){
            sum += x%10;
            x /= 10;
        }
        return sum;
    }
};

int main(){

    Solution s;

    return 0;
}
