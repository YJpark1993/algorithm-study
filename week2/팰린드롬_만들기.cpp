//
// Created by Yujin Park on 2019-08-17.
//
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str;
int MIN=23456789;
bool isPall(string cstr) {
    int left=0, right=cstr.length()-1;
    bool isPal=true;
    while(isPal && left<right) {
        if(cstr[left++] != cstr[right--]) isPal=false;
    }
    return isPal;
}
void check(int cur) {
    string checkStr=str;
    if(cur>=str.length()-1) return ;
    for(int i=cur; i>=0; i--) {
        checkStr+=str[i];
    }
    if(isPall(checkStr)) MIN=min(MIN, (int)checkStr.length());
    check(cur+1);
}
int main() {
    cin>>str;
    if(isPall(str)) {
        cout<<str.length()<<endl;
        return 0;
    }
    check(0);
    cout<<MIN<<endl;


}