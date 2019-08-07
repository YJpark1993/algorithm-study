//
// Created by Yujin Park on 2019-07-23.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int D,E,S;
int edge[1001][1001];
bool node[1001];
void dfs(int cur) {
    node[cur]=true;
    cout<<cur<<" ";
    for(int i=1; i<=D; i++) {
        if(edge[cur][i]>0 && !node[i]) {
            dfs(i);
        }
    }
}
void bfs(int start) {
    queue<int> que;
    que.push(start);
    while(!que.empty()) {
        int qsize = que.size();
        for(int i=0; i<qsize; i++) {
            int cur = que.front();
            que.pop();
            if(node[cur]) continue;
            node[cur]=true;
            cout<<cur<<" ";
            for(int j=1; j<=D; j++) {
                if (edge[cur][j] > 0 && !node[j]) {
                    que.push(j);
                }
            }
        }
    }

}
//bool compare(Edge lhs, Edge rhs) {
//    return lhs.start == rhs.start ? lhs.des<rhs.des : lhs.start<rhs.start
//}
int main() {
    cin>>D>>E>>S;
    for(int i=0; i<E; i++) {
        int s,d;
        cin>>s>>d;
        edge[s][d]=edge[d][s]=1;

    }
    dfs(S);
    cout<<endl;
    fill(node, node+D+1, false);
    bfs(S);
}