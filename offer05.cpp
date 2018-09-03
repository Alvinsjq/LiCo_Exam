#include <iostream>

using namespace std;

class Solution {
public:
    /*
     * @param string: An array of Char
     * @param length: The true length of the string 注意是总容量
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // write your code here'
        if(string == nullptr && length<=0)
        	return 0;
        int strlen = 0;
    	int num_space = 0;
    	int i = 0;
    	while(string[i]!='\0'){
    		if(string[i] == ' '){
    			num_space++;
    		}
    		strlen++;
    		i++;
    	}
    	int newlen = strlen + 2 * num_space;
    	int end = strlen;  
    	int newend = newlen;
    	
    	if(newend > length) return 0;

    	while(end >= 0 && end < newend){

    		if(string[end] != ' '){
    			string[newend--] = string[end];
    			
    		}else{
    			string[newend--] = '0';
    			string[newend--] = '2';
    			string[newend--] = '%';
    			
    		}
    		end--;
    	}
    	return newlen;
    }
};
int main(){
	/* code */
	Solution s;
	char str[100] = "Mr John Smith";
	int length = 100;
	int rt = s.replaceBlank(str,length);
	cout<<"rt:"<<rt<<endl;
	for(char c : str)
		cout<<c<<" ";
	return 0;
}