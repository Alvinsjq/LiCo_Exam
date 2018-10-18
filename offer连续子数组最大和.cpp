#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:

    int FindGreatestSumOfSubArray(vector<int> array) {
        int nowmax = array[0];
        int _max = array[0];
        for(int i=1;i<array.size();i++){
           _max = max(_max+array[i],array[i]);
            nowmax = max(nowmax,_max);
        }
        return nowmax;
    }
};


int main(){

    vector<int> v;
    v.push_back(1);
    v.push_back(-2);
    v.push_back(3);
    v.push_back(10);
    v.push_back(-4);
    v.push_back(7);
    v.push_back(2);
    v.push_back(-5);

    Solution s;

    cout << s.FindGreatestSumOfSubArray(v) << endl;
    return 0;
}
