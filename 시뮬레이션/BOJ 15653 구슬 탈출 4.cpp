
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

int dx[4] = {1,-1,0,0}; // R L D U
int dy[4] = {0,0,1,-1};
char arr[11][11];

char c[4] = {'D', 'U', 'R', 'L'};
// (1,0)이 D, (-1,0)이 U, (0,1)이 R, (0,-1)이 L이다.
// 이게 반전되서 해야 나오는 것이 구할 때에 애초에 x,y축을 반전하여 써서 그런거 같기도 싶다...

string dir;
queue<string>balldir;

int rx, ry;
int bx, by;
int hx, hy;
int ans = 0;
bool check[11][11][11][11] = {0,};

int BFS(){
    
    queue<pair<int, int>>blue;
    queue<pair<int, int>>red;
    blue.push({bx, by});
    red.push({rx, ry});
    // 빨간 공과 파란 공의 위치를 queue에 넣어줌
    
    ans = 0;
    
    while(!blue.empty()){
        int sizes = blue.size();
        
        while(sizes--){
            int redx = red.front().first;
            int redy = red.front().second;
            int bluex = blue.front().first;
            int bluey = blue.front().second;
            
            dir = balldir.front();
            // 공의 방향을 가진 큐의 front를 입력 받음
            balldir.pop();
            // 그러고 pop
            
            red.pop();
            blue.pop();
            // 각각 공의 현재 위치가 redx, redy 와 bluex, bluey
            
            if(arr[redx][redy] == 'O')
                return ans;
            // 공이 O에 들어가면 바로 ans를 리턴한다.
            
            for(int i=0;i<4;i++){
                int nrx = redx;
                int nry = redy;
                int nbx = bluex;
                int nby = bluey;
                string nextdir = dir;
                // dir를 먼저 nextdir에 저장해준다.
                
                while(arr[nrx + dx[i]][nry + dy[i]] != '#' && arr[nrx][nry] != 'O'){
                    nrx += dx[i];
                    nry += dy[i];
                    
                }
                // 이동한 방향이 #가 아니고, O도 아닐 경우 이동한다.
                while(arr[nbx + dx[i]][nby + dy[i]] != '#' && arr[nbx][nby] != 'O'){
                    nbx += dx[i];
                    nby += dy[i];
                }
                // 이동한 방향이 #가 아니고, O도 아닐 경우 이동한다.
                
                if(nrx == nbx && nry == nby){     // 빨간 공과 파란 공의 위치가 같을 경우
                    if(arr[nrx][nry] == 'O')
                        continue;
                    // 그 위치가 구멍이면 continue
                    
                    // 더 많이 이동 한 구슬이 원래 자기 위치로
                    if((abs(nrx - redx) + abs(nry - redy)) > (abs(nbx - bluex) + abs(nby - bluey))){        // 빨간 구슬이 더 많이 이동 하였을 경우에
                        nrx -= dx[i];
                        nry -= dy[i];
                    }       // 빨간 구슬을 다시 원래대로 돌아가게 함
                    else{
                        nbx -= dx[i];
                        nby -= dy[i];

                    }       // 파란 구슬이 더 많이 이동 하였을 경우 다시 원래대로
                }
                
                if(check[nrx][nry][nbx][nby])
                    continue;
                // 다음 이동한 각각 위치들을 check 하였을 경우 true일 경우 continue
                red.push({nrx, nry});
                blue.push({nbx, nby});
                
                nextdir.push_back(c[i]);
                balldir.push(nextdir);
                // 모든 계산이 끝났을때, 그 방향에 따른 이동방향을 nextdir 즉 방향을 알려주는 queue에
                // 넣어주고, balldir의 queue에 이 string을 push해준다.
                // 즉, 다음 방향을 추가해주고, 다음 방향이 추가된 문자열을 저장해준다.
                
                check[nrx][nry][nbx][nby] = 1;
                // 빨강과 파랑을 넣어주고, check를 true로 만들어준다.
                
            }
        }
        
        
        ans++;
        // 아닐 경우 ans를 늘려준다.
        
    }
    return -1;
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            
            if(arr[i][j] == 'R'){
                rx = i;
                ry = j;
                arr[i][j] = '.';        // 빨간 공을 저장해주고, .으로 바꾼다.
            }
            if(arr[i][j] == 'B'){
                bx = i;
                by = j;
                arr[i][j] = '.';        // 파란 공을 저장해주고, .으로 바꾼다.
            }
            if(arr[i][j] == 'O'){
                hx = i;
                hy = j;
            }
            
        }
    }
    
    balldir.push("");

    if(BFS() == -1)
        cout << "-1" << '\n';
    else{
        cout << ans << '\n';
//        cout << dir << '\n';
//        // dir에 front를 저장해주면서 그를 출력한다.
//        // queue의 string의 front이기에 전부를 넣어주기 때문에 dir를 출력 가능하다.
    }
    // 구멍에 들어갈 경우 -1을 출력 하지 않기에 else 에서 1을 출력해준다.
    
    return 0;
}

// 그냥 10이상인 경우만 빼주면 되는 거 같기도..?
// 구슬 탈출 문제 자체가 1만 풀어주면 좀 다 쉽게 풀리는 것 같다.
