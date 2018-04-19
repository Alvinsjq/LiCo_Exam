#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        //定义p[i,j]代表是否为回文字串
        //那么P[i,j] <- P[i+1,j-1] 并且 si=sj
        //当P[i,i]时 为 true
        //当P[i,i+1] <- si=si + 1
        //有了这么一个动态规划思路后关键就是如何走位
        int len = s.length();
        bool p[len][len];
        int i,j,max_=0;
        string res = "";
        for(i=len-1;i>=0;i--)
            for(j=i;j<len;j++)
                if(i == j)
                    p[i][j] = true;
                else if(i+1 == j)
                    p[i][j] =  (s[i]==s[i+1]);
                else
                    p[i][j] = (p[i+1][j-1] && s[i]==s[j]);

        for(i=len-1;i>=0;i--)
            for(j=i;j<len;j++){
                if(p[i][j])
                    if(max_<j-i){
                        res = s.substr(i,(j-i+1));
                        max_ = j-i;
                    }
            }
        if(res==""&&len>=1)
            res = s[0];

        return res;
    }
};


int main(){
    string s;
    Solution sol;
    while(cin>>s)
        cout<<sol.longestPalindrome(s)<<endl;
    return 0;
}
