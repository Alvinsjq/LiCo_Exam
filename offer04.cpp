#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	bool find(int matrix[][4], int rows, int columns, int x){
		int row = 0;
		int col = columns - 1;
		if(matrix != NULL && rows > 0 && columns > 0 ){
			while(row < rows && col > 0){
				if(matrix[row][col] == x)
					return true;
				else
					if(matrix[row][col] > x)
						col --;
					else 
						row ++;
			}
		}
		return false;
	}
};


int main(){

	Solution s;
	int matrix[4][4]= {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	int rows = 4;
	int columns = 4;
	cout<<s.find(matrix, rows, columns, 7)<<endl;
	cout<<s.find(matrix, rows, columns, 5)<<endl;

}