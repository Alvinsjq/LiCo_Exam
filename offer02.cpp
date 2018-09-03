#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	//nums 是已经排好序的数组
	vector<int> findDuplication(int nums[], int len){
		vector<int> v;
		for(int i = 0; i < len; i++){
			if(nums[i] != i){
				if(nums[nums[i]] == nums[i]){
					//cout<<nums[i]<<endl;
					v.push_back(nums[i]);
				}
				else{
					int temp = nums[i];
					nums[i] = nums[nums[i]];
					nums[nums[i]] = temp;
				}
			}
				
		}
		return v;
	}

		/**
		 *  通过二分范围来找到重复的数字，基于的原则是如果在数字 a-b 之间 有重复的数字
		 *  的话，那么这里的个数肯定会大于
		 **/
	int findDuplication2(int nums[], int len, int start, int end){
		int mid = 0;
		while(start<end){
			mid = (start+end)/2;
			int lcount = 0;
			int rcount = 0;
			for(int i=0;i<len;i++){
				if(nums[i]>=start && nums[i]<= mid)
					lcount++;
				if(nums[i]> mid && nums[i]<=end)
					rcount++;
			}
			if(lcount > mid-start+1){
				end = mid;
			}else if(rcount > end - mid){
				start = mid + 1;
			}
		}
		//cout<<start<<endl;
		return start;
	}
}; 

int main(){
	Solution s;
	// int a[] = {0,1,2,3,3,4,5,6};
	int a[] = {2,3,5,4,3,2,6,7};
	int x = s.findDuplication2(a,8,1,7);
	cout<<x<<endl;
}