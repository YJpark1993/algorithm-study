//
// Created by Yujin Park on 2019-09-04.
//
#include <iostream>
using namespace std;
int house[1001][3];
int dp[1001][3];
int main() {
    int N;
    cin>>N;
    for(int i=0; i<N; i++) {
        int r,g,b;
        cin>>r>>g>>b;
        house[i][0]=r;
        house[i][1]=g;
        house[i][2]=b;
    }
    dp[0][0]=house[0][0];
    dp[0][1]=house[0][1];
    dp[0][2]=house[0][2];
    for(int i=1; i<N; i++) {
        dp[i][0] = house[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = house[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = house[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }
    int result = min(dp[N-1][0], min(dp[N-1][1], dp[N-1][2]));
    cout<<result<<endl;
}
