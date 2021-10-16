
#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>
#include <map>
#include <set>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;

int ans;
char st[21][21];
bool check[21][21];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

vector<pair<int, int>> coin;

bool out(int a, int b){
    if(a < 0 || a >= n || b < 0 || b >= m)
        return true;
    else
        return false;
}
// 넘어갈 경우 true 아닐경우 false

void DFS(int x1, int x2, int y1, int y2, int num){
    
    if(num > 10)
        return;
    // 10번 보다 많을 경우 그냥 리턴한다.
    
    if(num >= ans)
        return;         // 최소 보다 크면 바로 return
    if(out(x1, y1) && out(x2, y2))
        return;
    // 둘다 넘을 경우도 그냥 리턴
    
    // ------------- 둘다 성공 ------------
    if(out(x1, y1) && !out(x2, y2)){
        ans = min(ans, num);
        return;
    }
    // 첫번째가 아웃하고 두번째가 in
    
    if(!out(x1, y1) && out(x2, y2)){
        ans = min(ans, num);
        return;
    }
    // 두번째가 아웃하고 첫번째가 in
    
    for(int i=0;i<4;i++){
        int nx1 = x1 + dx[i];
        int nx2 = x2 + dx[i];
        int ny1 = y1 + dy[i];
        int ny2 = y2 + dy[i];
        
        if(st[nx1][ny1] == '#'){
            nx1 = x1;
            ny1 = y1;           // 벽이면 그냥 취소하고 다시 돌아감
        }
        if(st[nx2][ny2] == '#'){
            nx2 = x2;
            ny2 = y2;           // 두번째 코인도 벽이면 그냥 취소하고 다시 돌아감
        }
        DFS(nx1, nx2, ny1, ny2, num+1);
        // 그 다음 좌표와 숫자를 증가시켜서 한번 더 해줌
    }
    
    
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> st[i][j];
            
            if(st[i][j] == 'o')     // 코인의 위치를 발견하면 그 좌표를 벡터에 넣어줌
                coin.push_back({i, j});
        }
    }
    
    ans = MAX;
    DFS(coin[0].first, coin[1].first, coin[0].second, coin[1].second, 0);
    // 코인의 좌표로 해준다.
    // x1, y1 은 첫번째 코인
    // x2, y2 는 두번째 코인
    
    if(ans == MAX)
        cout << "-1" << '\n';
    else
        cout << ans << '\n';
    
    
    return 0;
}

// 모두 확인하지만 시간복잡도가 O(4^10)이라서 가능


