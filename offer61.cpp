#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
      if(numbers.size()<1)
            return false;
        //1. 排序
        sort(numbers.begin(),numbers.end());
        int i;
        int zero_num = 0;
        int dis = 0;
        //2. 统计零的次数和数字间的间隔总数
        for(i=0;i<numbers.size()-1;i++)
            if(numbers[i] == 0)
                zero_num ++;
        int j = zero_num;

        while(j < numbers.size()-1){
            if(numbers[j] == numbers[j+1])
                return false;
            dis += numbers[j+1] - numbers[j] -1;
            j ++;
        }
        // 3. 判断间隔
        if(dis<=zero_num)
            return true;
        else
            return false;
    }
};


int main(){
    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);

    Solution s;

    cout<<s.IsContinuous(v)<<endl;


}


