#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 30

int n;
bool isusedcol[MAX];        // 같은 열에 존재하는지 true false로 확인
bool isusedright[MAX];      // 우측 상단 대각선에 존재하는지 true false로 확인
bool isusedleft[MAX];       // 좌측 상단 대각선에 존재하는지 true false로 확인
int num = 0;

void solve(int level){
    if(level == n){     // n이면 탈출
        num++;      // 개수 세기
    return;
}
    for(int i=0;i<n;i++){       // 탐색
        if(isusedcol[i] || isusedright[i+level] || isusedleft[level-i+n-1])// 죄선 대각은 i-j 우선 대각은 i+j
            continue;       // 3개 중 하나라도 만족하지 않으면, continue
        // 우측 상단의 대각선의 경우 i+level로 다 같다. 좌측도 그렇다
        //i>j일때 i-j가 음수가 될수 있으므로, 1-n을 더했을 때 0을 만드려면, i-j+n-1이어야 하기에
        isusedcol[i] = true;
        isusedright[i+level] = true;
        isusedleft[level-i+n-1] = true;
        solve(level+1);     // 아래 행으로 넘어간다.
        isusedcol[i] = false;
        isusedright[i+level] = false;
        isusedleft[level-i+n-1] = false;
    }

}

int main(){
    cin >> n;
    solve(0);
    cout << num << '\n';
    
    return 0;
}

