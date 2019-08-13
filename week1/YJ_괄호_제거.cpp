//
// Created by Yujin Park on 2019-08-13.
//
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
stack<int> stk;
typedef pair<int, int> Brk;
vector<Brk> vec;
vector<string> result;
bitset<200> bit;
string str;

void insertResult(bitset<200> bit) {
    string rst;
    for(int i=0; i<str.length(); i++) {
        if(bit[i]==true) rst += str[i];
    }
    if(find(result.begin(), result.end(), rst) == result.end()) result.push_back(rst);
}
void check(int cur) {
    if(cur >= vec.size()) return ;
    insertResult(bit);
    for(int i=cur; i<vec.size(); i++) {
        int nleft = vec[i].first;
        int nright = vec[i].second;
        if(!bit[nleft]) {
            bit.set(nleft,1);
            bit.set(nright,1);
            check(i);
            bit.set(nleft,0);
            bit.set(nright,0);
        }
    }
}
int main() {
    cin>>str;
    for(int i=0; i<str.length(); i++) {
        if(str[i] == '(') {
            stk.push(i);
        } else if(str[i] == ')') {
            int left = stk.top();
            stk.pop();
            vec.push_back(make_pair(left, i));
        }else {
            bit.set(i, 1);
        }
    }

    check(0);
    sort(result.begin(), result.end());
    result.erase(result.begin());
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<endl;
    }

}
