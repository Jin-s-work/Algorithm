
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
int h, w;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
// 이의 순서는 달팽이처럼 도는 대로 한다.

int arr[1001][1001];
int x, y;
int nx, ny;
int dir;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=n*n;i>0;i--){
        arr[x][y] = i;
        // 처음에는 (x, y)에 i를 넣어준다.
        
        if(i == m){
            nx = x + 1;
            ny = y + 1;
        }
        // i가 m일 경우, 즉 위치의 경우 1씩 더해준다.
        
        if(x + dx[dir] < 0 || x + dx[dir] >= n || y + dy[dir] < 0 || y + dy[dir] >= n || arr[x + dx[dir]][y + dy[dir]] != 0)
            dir = (dir + 1) % 4;
        // 범위를 넘거나 이동한 arr가 0이 아닐 경우 방향을 바구어 준다.
        // 방향은 1을 더해서 4의 나머지로 계속 바뀌어 간다.
        
        x = x + dx[dir];
        y = y + dy[dir];
        // 달팽이의 방향대로 더해준다.
        // 좌표를
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
    
    cout << nx << " " << ny;
    // 이동한 좌표를 출력한다.
    
    return 0;
}


// 구현 왜 이렇게 복잡하고 어렵디....
// 티어 낮아도 잘 모르겠다 솔직히...
