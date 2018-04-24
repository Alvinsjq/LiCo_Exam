#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{

public:
	vector<string> findMissingRanges(int a[],int start,int end){
		vector<string> v;
		int pre = start-1; //初始化pre为最小区间数-1；

		for (int i = 0; i <= length(a); i++){
			/* code */
			int curr = (i ==  length(a)) ? curr = end+1 : a[i]; //获取当前值，如果i数组长度以内的话，当前值为数组i索引下的值，若索引已经是数组最长处，那自然是最大区间树+1；
			if(curr - pre >= 2){ // 如果pre 与 curr 之间的距离大于等于2 的话，才有必要输出结果，不然哪来的间隔的数啊；
				v.push_back(getRange(pre+1, curr-1));//在vector中加入区间
			}
			pre = curr; //将curr的值传给pre，作为下一个索引的pre值
		}
	}

	string getRange(int from,int to){
		return (from == to) ? to_string(from) : to_string(from)+"->"+to_string(to);
	}

	template<class T>
	int length(T& arr){
	    //cout << sizeof(arr[0]) << endl;
	    //cout << sizeof(arr) << endl;
	    return sizeof(arr) / sizeof(arr[0]);
	}

};


int main(){

	int a[] = {0,1,3,50,75};
	int start = 0;
	int end = 99;
	Solution solution;
	vector<string> v = solution.findMissingRanges(a,start,end);
	for (string a : v)
		cout<<a<<endl;
	

}