#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        s = trim(s);
        bool isNum = false;
        bool ispoint = false;
        bool isE = false;
        int i;
        for(i=0;i<s.length();i++){
            if('0'<=s[i]&&s[i]<='9')
                isNum = true;
            else if(s[i]=='.'){
                if(ispoint||isE)
                    return false;
                ispoint = true;
            }else if(s[i]=='e'){
                if(isE||!isNum)
                    // e前面都没有数字
                    return false;
                isNum = false;
                isE = true;
            }else if(s[i]=='-'||s[i]=='+'){
                if(i!=0 && s[i-1]!= 'e')
                    //-+号又不在第一个，并且前面又不是e;
                    return false;
            }else
                return false;
        }
        return isNum;

    }

    string trim(string s){
        if(s.empty()) return s;
        s.erase(0,s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ')+1);
        return s;
    }
};

int main(){
    Solution s;
    string str;
    while(cin>>str){
        string result;
        if(s.isNumber(str))
           cout<<"true"<<endl;
        else
           cout<<"false"<<endl;
    }

    return 0;
}
