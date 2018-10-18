#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> v;
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(rows == 0)
            return matrix;

        int row = 0;
        int col = -1;

        while(true){
            for(int i=0;i<cols;i++)
                v.push_back(matrix[row][++col]);
            if(--rows == 0) break;

            for(int i=0;i<rows;i++)
                v.push_back(matrix[++row][col]);
            if(--cols ==0) break;

            for(int = 0;i<cols;i++)
                v.push_back(matrix[row][--col]);
            if(--rows == 0) break;

            for(int i=0;i<rows;i++)
                v.push_back(matrix[++row][col]);
            if(--cols == 0) break;
        }
        return v;
    }
};


int main(){

    return 0;
}
