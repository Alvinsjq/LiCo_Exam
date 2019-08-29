/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.04%)
 * Total Accepted:    527.6K
 * Total Submissions: 1.6M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight","flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
private:
    string compare2(string a, string b){
        int len1 = a.length();
        int len2 = b.length();
        int len = len1 < len2 ? len1 : len2;
        int i;
        for(i = 0; i < len; i++){
            if(a.at(i) != b.at(i))
                break;
        }
        return a.substr(0,i);
    }

    string CommonPrefix(vector<string>& str, int l, int r){
        if(l == r)
            return str[l];
        else
        {
            int mid = (l + r)/2;
            string left = CommonPrefix(str, l, mid);
            string right = CommonPrefix(str, mid+1, r);
            return compare2(left, right);
        }
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        return CommonPrefix(strs, 0, strs.size()-1);
    }
};

