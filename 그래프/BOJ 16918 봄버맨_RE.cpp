#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <functional>
#include <map>
#include <unordered_map>
#include <set>
#include <sstream>

// control i
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


char arr[201][201];
queue<pair<int, int>>q;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m >> k;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'O'){
                q.push({i, j});         // 처음 폭탄의 위치를 q에 넣어준다.
            }
        }
    }
    
    bool check = true;
    while(--k){          // 시간이 지나가는 것을 표시하는데 k-1초 뒤의 k번째 상태를 보여줘야하므로 먼저 줄임
        if(check){          // 1초가 지났을 경우 모두 0으로 해준다.
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    arr[i][j] = 'O';
                }   // 그냥 모두 O으로 해주는 것
            }
            // 2의 배수일 때는 항상 모든 칸에 폭탄을 넣어준다.

            check = false;
            continue;
            // check가 true일 경우 폭탄을 모두 바꿨으므로 false로 하고 continue
            // 첫 1초에만 이렇게 하는 것이다. 다음에는 안함
        }
        
        // 폭탄을 터질 때를 생각한다
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            arr[x][y] = '.';            // 그 다음 부터 이므로 .로 바꾸어준다.
            q.pop();
            // arr와 현재의 좌표를 x,y에 저장해논다.
            // 처음의 폭탄이 터졌으므로 .으로 바꾸어 주는 것
            
            for(int l=0;l<4;l++){
                int nx = x + dx[l];
                int ny = y + dy[l];
                
                if(nx > n || ny > m || nx <= 0 || ny <= 0 || arr[nx][ny] == '.')
                    continue;
                // 범위를 벗어나거나 .일 경우에는 그냥 continue로 넘기
                
                arr[nx][ny] = '.';
                // 범위에 해당 되는 경우 .으로 바꾼다. 즉 상하좌우 한번만 해주는 것
                // 폭탄이 터져서 주위가 다시 .으로 바뀌는 것
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr[i][j] == 'O')
                    q.push({i, j});
                // 폭탄일 경우 q에 push한다.
            }
        }
        check = true;
        // 이때에는 false였으니까 다시 true로 해준다.
        // 즉 true가 아닌 false라서 진행되었던건 2초 지났을 떄(?) 였기 때문에
        // 다음인 3초(?)에서는 다시 true로 진행
        
        // 정확한 숫자라기 보다는 2의 배수로 생각해주면 편함
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << arr[i][j];
        }
        cout << '\n';
    }
    
    // 0초 : 처음 폭탄
    // 1초 : 아무것도 하지 않음
    // 2초 : 폭탄 없는 위치에 폭탄을 설치
    // 3초 : 심은 폭탄 터짐
    // 4초 : 폭탄 없는 위치에 폭탄을 설치
    
    
    
    return 0;

}


