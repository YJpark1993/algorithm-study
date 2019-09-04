//
// Created by Yujin Park on 2019-08-17.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int RES=2e9;
typedef pair<int,int> Location;
string fullString;
vector<string> strings;
bool compare(string lhs, string rhs) {
    return lhs.length()>rhs.length();
}
void check(int cur, Location loc) {
    if(cur>=N) {
        RES=min(RES, loc.second-loc.first);
        return;
    }
    string curString = strings[cur];
    string subString = fullString.substr(loc.first, loc.second-loc.first);

    if(subString.find(curString) != string::npos) {
        check(cur+1, loc);
        return;
    }
    for(int i=0; i<fullString.length()-curString.length()+1; i++) {
        if(curString[0] == fullString[i]){
            for(int j=0; j<curString.length(); j++) {
                if(curString[j] != fullString[i+j]) break;
                if(j==curString.length()-1) {
                    check(cur+1, make_pair(min(loc.first, i), max(loc.second, i+(int)curString.length())));
                }
            }
        }
    }

}
int main() {
    std::cin.sync_with_stdio(false);

    int _;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> _ >> str;
        strings.push_back(str);
    }
    cin >> _ >> fullString;
    sort(strings.begin(), strings.end(), compare);
    check(0, make_pair(fullString.length(), 0));
    cout << RES << endl;
}