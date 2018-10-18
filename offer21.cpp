#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void reOrderArray(vector<int> &array) {

    }

    void reOrderArray_easy(vector<int> &array){
        int len = array.size();
        int i = 0;
        int j = len - 1;
        while(i < j){
            while((array[i] & 0x1) == 1) i++;
            while((array[j] & 0x1) == 0) j--;
            if(i<j){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        vector<int> :: iterator it = array.begin();
        for(;it!=array.end();it++){
            if((*(it+1) & 0x1)==0){
                sort(array.begin(),it+1);
                sort(it+1,array.end());
                break;
            }
        }
    }
};


int main(){

    Solution s;
    vector<int> v;
    v.push_back(1);v.push_back(2);v.push_back(3);v.push_back(4);v.push_back(5);v.push_back(6);v.push_back(7);
    s.reOrderArray_easy(v);
    //v.push_back(3);v.push_back(7);v.push_back(1);v.push_back(5);v.push_back(2);v.push_back(6);v.push_back(4);

    for(int a : v)
        cout << a <<endl;

    return 0;
}
