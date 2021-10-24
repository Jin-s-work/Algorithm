
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


int arr[17][17];
int ans = 0;
int dx[3] = {0,1,1};
int dy[3] = {1,1,0};
// 이걸 순서를 맞춰서 넣기에 평소처럼 아무렇게 하면 안된다.
// 순서대로 가로, 대각선, 세로이다.

// 따라서 여기서도 가로, 대각선, 세로 순서이다.
struct dir{
    int x, y, z;
};

queue<dir>q;

void move(int x, int y, int z, int k){
    int nx = x + dx[k];
    int ny = y + dy[k];
    int nk = k;
    
    if(arr[nx][ny] == 0 && nx > 0 && nx <= n && ny > 0 && ny <= n){
        if(k == 1){     // 1일 경우는 대각선일 때,, 이때 왼쪽과 위를 체크해 주어야 한다.
            if(arr[nx-1][ny] == 1 || arr[nx][ny-1] == 1)
                return;
            // 1일 경우 그냥 리턴
        }
        q.push({nx, ny, nk});
        // 아닐 경우 nx, ny, nk로 가도 되므로 푸시해준다.
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
        }
    }
    
    q.push({1, 2, 0});
    // 처음엔 1,1 1,2 에 가로로 되어있으므로 1, 2, 0 이다.
    
    while(!q.empty()){       // q가 있는 동안
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        
        q.pop();
        // 저장해주고 pop
        
        if(x == n && y == n)
            ans++;
        // n n에 도달할 경우 ans를 더해줌
        // 방법의 개수이므로 move를 해서 그 결과가 n,n까지 갈때를 구하는 것이므로
        // move를 해주면서 nx,ny를 큐에 push해주는데, 이때 n,n이 나오면 경우의 수가 늘어잠
        
        
        if(z == 0){     // z가 0일 경우 즉 가로 일때
            for(int i=0;i<2;i++){
                move(x, y, z, i);
            }
            // x, y, z에 따라서 0, 1 이동을 해준다. 가로이므로..
        }
        else if(z == 1){        // z가 1일 경우 즉 대각선일때
            for(int i=0;i<3;i++){
                move(x, y, z, i);
            }
            // 0, 1, 2로 해준다. 대각선 이므로
        }
        else{       // z가 2일 경우 세로 인 경우로
            for(int i=1;i<3;i++){
                move(x, y, z, i);
            }
            // 1,2를 해준다. 세로 이므로
        }
        
        
    }
    
    cout << ans;
    
    return 0;
}

