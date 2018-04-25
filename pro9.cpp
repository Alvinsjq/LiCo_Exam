#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int o_x = x;
        int palindrome = 0;
        if(x<0)
            return false;
        while(x!=0){
            palindrome = palindrome * 10 + x % 10;
            x /= 10;
        }
        if(palindrome == o_x)
            return true;
        else
            return false;
    }
};


int main(){
    int x;
    Solution s;
    while(cin>>x)
        cout<<s.isPalindrome(x)<<endl;
    return 0;
}
