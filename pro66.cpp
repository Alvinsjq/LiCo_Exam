#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int i;
        for(i=len-1;i>=0;i--){
            if(i>0 && (digits[i]+1) == 10){
                digits[i] = 0;
                continue;
            }else if(i==0 && (digits[i]+1) == 10){
                //处理全部需要进位的情况
                digits[i] = 0;
                vector<int>::iterator it;
                it = digits.begin();
                it = digits.insert (it,1);
                return digits;

            }else{
                digits[i] += 1;
                break;
            }
        }
        return digits;
    }
};


int main(){
    vector<int> v;
    Solution s;

    v.push_back(4);
    v.push_back(2);
    v.push_back(0);
    v.push_back(9);
/*
    vector<int>::iterator it;
    it = v.begin();
    it = v.insert (it,1);

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
*/

    vector<int> res;
    res = s.plusOne(v);
    for(int i=0;i<res.size();i++)
       cout<<res[i]<<" ";
    cout<<endl;

}



