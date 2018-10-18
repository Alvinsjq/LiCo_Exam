#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool is(vector<int> seq, int begin, int end){
        if(end == begin)
            return true;
        int root = seq[end];

        int i,j;
        for(i=begin;i<end;i++)
            if(seq[i]>=root)
                break;
        for(j=i;j<end;j++)
            if(seq[j]<root)
                return false;
        if(i==end)
            return false;
        bool left = is(seq,begin,i-1);
        bool right = is(seq,i,end-1);

        return left && right;
    }

    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() > 0)
            return is(sequence,0,sequence.size()-1);
        else
            return false;
    }
};

int main(){
    Solution s;
    vector<int> seq;
    seq.push_back(5);
     seq.push_back(7);
      seq.push_back(6);
       seq.push_back(9);
        seq.push_back(11);
         seq.push_back(10);
          seq.push_back(8);
    cout<< s.VerifySquenceOfBST(seq) <<endl;
    return 0;
}
