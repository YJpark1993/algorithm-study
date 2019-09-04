//
// Created by Yujin Park on 2019-08-10.
//
#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    cin>>str;
    int left=0, right=str.length()-1;
    bool isPal=true;
    while(isPal && left<right) {
        if(str[left++] != str[right--]) isPal=false;
    }
    if(isPal) cout<<1<<endl;
    else cout<<0<<endl;

}