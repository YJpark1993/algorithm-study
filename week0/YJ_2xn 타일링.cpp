#include <iostream>
#include <algorithm>
using namespace std;
int N;
long long dp[1001];
int main() {
    cin>>N;
    dp[1] = 1; dp[2] = 2;
    for(int i=3; i<=N; i++) {
        dp[i] = dp[i-2] + dp[i-1];
        dp[i] %= 10007;
    }
    cout<<dp[N];
}
