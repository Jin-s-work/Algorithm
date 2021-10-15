
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

bool check[501][501] = {false};
int arr[501][501];
int ans;

int dx[4] = {0,0,1,-1};
int dy[4] = {1, -1, 0, 0};

void DFS(int a, int b, int sum, int num){
    
    check[a][b] = true;     // 지나갔으니까 true
    if(num == 3){
        ans = max(ans, sum);
        return;
    }           // ans는 sum중 큰거로 return
    
    for(int i=0;i<4;i++){
        int nx = a + dx[i];
        int ny = b + dy[i];
        
        if(nx < 0 || nx > n || ny < 0 || ny > m)
            continue;           // 범위를 넘었을때 continue
        if(check[nx][ny])
            continue;           // 다음 방향인 nx, ny 가 true일 경우 continue
        
        DFS(nx, ny, sum + arr[nx][ny], num + 1);  // sum에 arr[nx][ny] 넣어주고 횟수도 1 증가
        check[nx][ny] = false;      // 그러고 false로 만들어준다.
    }
    
}       // 모든 도형이 DFS로 갈 수 있는 최소 거리를 뜻하므로 이걸로 할 수있다. (ㅜ 빼고)


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            memset(check, false, sizeof(check));
            // 계속 check를 false로 초기화 해주어야 DFS가 되는거 같기도..?
            // 그래서 한 5%쯤에서 계속 틀린거 같다.
            
            DFS(i, j, arr[i][j], 0);        // i, j부터 시작은 0회 부터
                    
            if(i >= 1 && j < m - 2){        // ㅗ      얘도 제일 가운데 위부터 시작
                int up = 0;
                up = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i-1][j+1];
                
                if(up > ans)
                    ans = up;
            }
            
            if(i < n - 1 && j < m - 2){      // ㅜ       // 아래로 두개 오른쪽으로 3개라서
                int down = 0;
                down = arr[i][j] + arr[i+1][j+1] + arr[i][j+1] + arr[i][j+2];
                
                if(down > ans)
                    ans = down;
            }
            
            if(i < n - 2 && j < m - 1){       // ㅏ
                int right = 0;
                right = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j+1];
                
                if(right > ans)
                    ans = right;
            }
            
            if(i < n - 1 && j < m - 1 && i >= 1){   // ㅓ인데 ㅓ에서 가운데 부터 시작
                int left = 0;                       // 그래서 n-1, m-1까지고 i>=1
                left = arr[i][j] + arr[i-1][j+1] + arr[i][j+1] + arr[i+1][j+1];
                
                if(left > ans)
                    ans = left;
                
            }
        }
    }
    
    
    
    cout << ans;
    
    
    return 0;
}


// ㅡ, ㅁ, ㄴ,
// ㅇ
// ㅇ ㅇ
//   ㅇ  모양들은 그냥 DFS로도 가능하다.

// ㅁ ㅁ ㅁ
//   ㅁ      만 따로 만들어주어야 함

// 회전이나 대칭을 시켜도 되므로 3가지 경우 더
