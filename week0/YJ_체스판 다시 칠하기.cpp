//
// Created by Yujin Park on 2019-07-28.
//

#include <iostream>
using namespace std;
int C,R;
int MIN = 2e9;
char map[50][50];
char chess[][9] =
        { {"WBWBWBWB"},
          {"BWBWBWBW"},
          {"WBWBWBWB"},
          {"BWBWBWBW"},
          {"WBWBWBWB"},
          {"BWBWBWBW"},
          {"WBWBWBWB"},
          {"BWBWBWBW"},
          {"WBWBWBWB"},
        };
void check(int sc, int sr) {
    int white=0, black=0;
    bool wflag=false, bflag=false;
    for(int c=sc; c<sc+8; c++) {
        for(int r=sr; r<sr+8; r++) {
            //check white first
            if(!wflag && map[c][r] != chess[c-sc][r-sr]) white++;
            if(!bflag && map[c][r] != chess[c-sc+1][r-sr]) black++;
            if(white>MIN) wflag= true;
            if(black>MIN) bflag= true;
            //if(MIN>white) break;
        }
    }
    MIN = min(MIN, min(white, black));
    //cout<<sc<<" "<<sr<<" "<<white<<" "<<black<<endl;
}
int main() {
    cin>>C>>R;
    for(int i=0; i<C; i++) {
        for(int j=0; j<R; j++) {
            cin>>map[i][j];
        }
    }

    for(int i=0; i<C-7; i++) {
        for(int j=0; j<R-7; j++) {
            check(i,j);
        }
    }
    cout<<MIN<<endl;
}