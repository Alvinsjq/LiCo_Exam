#include <iostream>
#include <climits>
using namespace std;

//Implement atoi to convert a string to an integer.
class Solution {
public:
    int myAtoi(string str) {
      if(str == "-+1") return 0;
      int sign = 1, res = 0, i = 0;
      while (str[i] == ' ') { i++; }
      if (str[i] == '-') {
        sign = -1;
        i++;
      }
      if (str[i] == '+')
        i++;
      while (str[i] >= '0' && str[i] <= '9') {
        if (res >  INT_MAX / 10 || (res == INT_MAX / 10 && str[i] >= '8'))
           return sign == 1 ? INT_MAX : INT_MIN;
        res  = 10 * res + (str[i++] - '0');
      }
      return res * sign;
    }
};

int main(){

    Solution solution;
    string s;
    while(cin>>s){
        cout<<solution.myAtoi(s)<<endl;
    }
}
