#include <string.h>
#include <iostream>
using namespace std;

class Solution {
public:
      bool hasPath(char* matrix, int rows, int cols, char* str){
        //当输入为空的时候
        if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
             return false;
        //初始化一个标记矩阵
        bool *visited = new bool[rows * cols];
        memset(visited,0,rows*cols);
        //开始回溯
        int pathLength = 0;
        for(int row=0;row<rows;row++)
            for(int col=0;col<cols;col++)
                //使用递归算法
                if(haspath(matrix,rows,cols,row,col,str,pathLength,visited))
                    return true;
        delete[] visited;
        return false;
    }

    bool haspath(const char* matrix, int rows, int cols, int row, int col, const char *str, int& pathLength, bool* visited){
        //当pathLength索引下的字符为空时，返回true
        if(str[pathLength] == '\0')
            return true;
        bool nexthaspath = false;
        //当坐标为row，col的格子和路径字符串中索引为pathLength的字符一样时,递归相邻格子
        if(row>=0 && row<rows && col>=0 && col<cols && matrix[row*cols + col] == str[pathLength] && !visited[row*cols + col]){
            //定位下一个str字符
            pathLength ++;
            visited[row*cols + col] = true;
            nexthaspath = haspath(matrix,rows,cols,row,col-1,str,pathLength,visited)
                    ||  haspath(matrix,rows,cols,row-1,col,str,pathLength,visited)
                    ||  haspath(matrix,rows,cols,row,col+1,str,pathLength,visited)
                    ||  haspath(matrix,rows,cols,row+1,col,str,pathLength,visited);
            if(!nexthaspath){
                pathLength--;
                visited[row*cols+col] = false;
            }
        }
        return nexthaspath;
    }
};

int main(){
    Solution s;
    return 0;
}
