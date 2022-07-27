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

// control i처
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


char arr[1001][1001];
bool check[1001][1001];
int fire_arr[1001][1001];       // 불의 시간을 저장

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int, int>> fire_Q;
int fire_x, fire_y, start_x, start_y;



void make_fire(){       // 불 만드는 함수 배열에다가 불이 퍼진 시간을 알려준다.
    
    while(!fire_Q.empty()){
        int qsize = fire_Q.size();
        
        for(int i=0;i<qsize;i++){
            int x = fire_Q.front().first;
            int y = fire_Q.front().second;
            fire_Q.pop();
            
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // 범위 안일 경우에
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    if(arr[nx][ny] != '#'){     // 벽이 아닐 경우에
                        if(fire_arr[nx][ny] > fire_arr[x][y] + 1){
                            fire_arr[nx][ny] = fire_arr[x][y] + 1;
                            fire_Q.push({nx, ny});
                        }   // 모든 fire_arr를 MAX로 했다.
                        // nx,ny가 x,y에서 1을 더한 것 보다 클 경우 (아직 안 지나갔을 경우)
                    }   // +1로 갱신을 해주고 다음의 nx,ny에서도 진행한다.
                }
            }
        }
    }
}



int BFS(int a, int b){
    queue<pair<pair<int, int>, int>>q;
    q.push({{a, b}, 0});
    check[a][b] = true;
    // 사람이 지나간 곳은 true
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        
        if(x == 0 || y == 0 || x == n-1 || y == m-1)
            return cnt+1;
        // 바깥으로 나갔을 경우 cnt에서 1증가 시켜서 내보낸다.
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                continue;
                // 범위 밖이면 무시
            }
            if(arr[nx][ny] != '#' && check[nx][ny] == false){
                if(fire_arr[nx][ny] > cnt + 1){
                    check[nx][ny] = true;
                    q.push({{nx, ny}, cnt+1});
                }
                // 벽이 아니고 check가 아직 방문 안되었을 경우
                // 벽도 아직 cnt보다 작을 경우에 즉 불이 타기 전
                // 불이 안 왔을 때도 MAX일 경우에도 작으니 이동 가능
                
                // check를 true로 해주고, cnt를 증가시켜서 큐에 넣어준다.
            }
        }
    }
    
    return -1;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool flag = false;
            cin >> arr[i][j];
            if(arr[i][j] == 'J'){
                start_x = i;
                start_y = j;
            }
            if(arr[i][j] == 'F'){
                fire_Q.push({i, j});
                fire_arr[i][j] = 0;
                flag = true;
            }
            // 불이 났을 경우 큐에 넣어주고 시작 된 부분을 0으로 시작한다.
            // flag 또한 true로 만든다.
            if(!flag)
                fire_arr[i][j] = MAX;
            // flag가 false일 경우 그냥 다 INF로 크게 해주고 시작
            // 불이 아직 안난 부분은 모두 그냥 MAX
        }
    }
    
    make_fire();
    int answer = BFS(start_x, start_y);
    
    if(answer == -1)        // 아무것도 안되고 -1로 빠지면 불가능
        cout << "IMPOSSIBLE" << '\n';
    else
        cout << answer << '\n';
    
    
    return 0;

}

// 불 맵을 먼저 만들어주고, 그에 저장된 시간 안에 사람이 갈 수 있는지 찾아야 한다.
