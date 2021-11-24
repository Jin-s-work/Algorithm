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

char arr[201][201];
queue<pair<int, int>>q;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'O')
                q.push({i, j});
        }
    }
    
    bool check = true;
    while(--k){       // k초의 시간이 지나고, k+1을 보여주는 것이 아니라 k-1초 뒤에 k번재 상태를 보여줘야함
        if(check){      // 처음의 시간에서 1초가 지나면 모두 O로 해준다.
            for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        arr[i][j] = 'O';
                    }
                }
            check = false;
            continue;
            // 하고 check false로 하고 continue
        }
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            arr[x][y] = '.';
            q.pop();
            // arr와 현재의 좌표를 x,y에 저장해놓고 시작
            
            for(int l=0;l<4;l++){
                int nx = x + dx[l];
                int ny = y + dy[l];
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == '.')
                    continue;
                // 범위를 넘거나 .이면 continue로 넘는다.
                arr[nx][ny] = '.';
                // 그 다음이 저 범위가 아닐 경우 .으로 바꾼다.
                // 모든 네 범위 다..!
            }
        }
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j] == 'O')
                    q.push({i, j});
                // O일 경우 계속 i,j를 푸쉬해줌
            }
        }
        check = true;
        // 다하고는 true로 해준다.
    
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j];
        }
        cout << '\n';
    }
    
    
    
    return 0;

}


// 2초, 4초 와 같은 경우에는 모두 O가 된다.
// BFS를 응용한 것이라 충분히 풀 수 있었는데, .과 O과 꽤나 복잡했다..
