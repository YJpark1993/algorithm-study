//
// Created by Yujin Park on 2019-08-19.
//
#include <iostream>
using namespace std;
long long arr[500000];
int main() {
    long long input;
    cin>>input;
    long long val=0;
    int idx=0;
    arr[idx]=3;
    while(val<=input) {
        idx++;
        val = arr[idx] = 4*idx + arr[idx-1] + 3;
    }
    long long c=2*idx+1, r=0;
    cout<<idx<<" "<<val<<" "<<arr[val]<<" "<<c<<" "<<r<<endl;
    if(val==input) {
        // nothing
    } else if(val+1==input) {
        c++;
    } else {
        val = arr[idx] = 4*idx + arr[idx-1] + 3;
        long long sub = val-input;
        c -= sub;
        r += sub;
    }
    cout<<c+1<<"/"<<r+1<<endl;
}
