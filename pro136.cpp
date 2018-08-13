#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]] += 1;
        }

        for(auto it = m.begin(); it!=m.end(); ++it)
          if(it -> second == 1)
            return it -> first; 
        return 0;
    }

    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<nums.size();i++)
            res ^= nums[i];
        return res;
    }
};


int main(){

  int num = 4 ^ 4 ^ 3;

  cout<< num <<endl;


}