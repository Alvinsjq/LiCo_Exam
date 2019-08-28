/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (27.05%)
 * Total Accepted:    486.8K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 *
 * You may assume nums1 and nums2 cannot be both empty.
 *
 * Example 1:
 *
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 *
 *
 * Example 2:
 *
 *
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 *
 *
 */
class Solution {
private:
	int getKth(vector<int> &n1, int s1, int e1, vector<int> &n2, int s2, int e2, int k){
		// 递求解
        int len1 = e1 - s1 + 1;
        int len2 = e2 - s2 + 1;
        if(len1 > len2)
            return getKth(n2, s2, e2, n1, s1, e1, k);
        if(len1 == 0)
            return n2[s2+k-1];
        if(k == 1)
            return n1[s1] < n2[s2] ? n1[s1] : n2[s2];

        int i = len1 < k/2 ? len1 : k/2;
        int j = len2 < k/2 ? len2 : k/2;

        i = s1 + i - 1;
        j = s2 + j - 1;

        if(n1[i] > n2[j])
            return getKth(n1, s1, e1, n2, j+1, e2, k-(j-s2+1));
        else
            return getKth(n1, i+1, e1, n2, s2, e2, k-(i-s1+1));
	}
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       // 该问题一般化为：求两个有序数组的第k个数，当k=(m+n)/2时为该问题的解

        int len1 = nums1.size();
        int len2 = nums2.size();

        int left = (len1+len2+1)/2;
        int rig = (len1+len2+2)/2;

        return (getKth(nums1, 0, len1-1, nums2, 0, len2-1, left) + getKth(nums1, 0, len1-1, nums2, 0, len2-1, rig)) * 0.5;
    }
};

