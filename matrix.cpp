#include<iostream>

using namespace std;

int main(){
    int n= 6;
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j = i+l-1;
            for(int k=i;k<=j-1;k++){
                cout << "m["<<i<<","<<j<<"]"<<endl;
            }
        }

    }

    return 0;
}
