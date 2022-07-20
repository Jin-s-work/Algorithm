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


bool flag[65];
bool check[11][11];
int wall[9][9];
int copy_wall[9][9];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int num, cnt, space;

vector<pair<int, int>>virus;
vector<pair<int, int>>zero;


void copy_map(){            // 바뀌기 전의 map을 copy해서 저장해놓는 함수 (tmp라고 생각해면 됨)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            copy_wall[i][j] = wall[i][j];
        }
    }
}

void BFS(int a, int b){         // BFS로 도는 함수
    queue<pair<int, int>>q;
    q.push({a, b});
    check[a][b] = true;
    // 처음 들어온 a,b에 관하여 push하고 true로 지나감 표시
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(check[nx][ny] == false && copy_wall[nx][ny] == 0){
                    copy_wall[nx][ny] = 2;
                    check[nx][ny] = true;       // 2로 바꾸고 지나갔읜 true로 바꾼다.
                    q.push({nx, ny});
                }
            }
            // 들어온 a,b에 BFS로 돈다.
            // 범위 안에 있을 경우이고, nx,ny에 대해 방문하지 않고 0인 경우에는
            //      퍼지는 경우이므로 2로 바꾸고, 이미 지났으므로 true로 바꾸어 준다.
            //      또한, 이 부분을 q에 넣어 다음 부분에 대해서도 진행해준다.
        }
    }
}

int count_space(){          // 공간의 개수를 찾는 함수
    int num = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(copy_wall[i][j] == 0)        // 0의 개수를 그냥 세주고 num 리턴
                num++;
        }
    }
    return num;
}

void spread(){          // 퍼뜨리는 함수
    int num = 0;
    copy_map();
    memset(check, false, sizeof(check));
    // 퍼뜨리는 부분에서는 먼저 맵을 커피하여 그것을 사용한다.
    // check도 false로 초기화 시켜준다.
    
    for(int i=0;i<space;i++){
        if(num == 3)            // 3번 진행한다는 뜻
            break;
        if(flag[i]){                 // flag가 true일 경우에
            int x = zero[i].first;   // DFS를 이용한 조합을 하므로, flag가 true일 떼
            int y = zero[i].second;  // 즉 조합을 하는 경우에만 1로 만들어주는 것이다.
            
            copy_wall[x][y] = 1;     // 0인 부분의 wall을 1로 바꾸어주고
            num++;                   // num을 늘려준다.
        }
    }
    
    for(int i=0;i<virus.size();i++){
        int x = virus[i].first;
        int y = virus[i].second;
        BFS(x, y);                  // virus에 관해서는 2가 있는 부분에서 BFS를 통해 spread 시킨다.
    }
    
    int tmp = count_space();        // 공간의 개수를 세서 tmp에 저장해주고
    cnt = max(cnt, tmp);            // 최대 인지를 비교해 준다.
}

void make_wall(int idx, int num){       // 벽을 만드는 함수 3개가 되면 퍼뜨린다.
    if(num == 3){                   // 3개가 되었을 경우 퍼트려서 확인한다.
        spread();
        return;
    }
    for(int i=idx;i<space;i++){     // 1부터 zero의 개수만큼
        if(flag[i])
            continue;               // 만약 flag가 true면 넘어가고
        flag[i] = true;
        make_wall(i, num + 1);      // 아닐 경우 num을 증가시켜주고 DFS 해준다.
        flag[i] = false;
    }
    // DFS를 통해서 1을 넣을 수 있는 조합들을 다 해보는 것이다.
    
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> wall[i][j];
            if(wall[i][j] == 0){
                zero.push_back({i, j});
            }
            else if(wall[i][j] == 2)
                virus.push_back({i, j});
        }       // 0과 2일 때 벡터에 넣어줌
    }
    // 벽을 3개 세워야 하는 시스템
    
    space = zero.size();        // 0의 개수를 세준다.
    
    make_wall(0,0);
    cout << cnt;
                           
    return 0;

}

// 예전의 코드를 보고 적당히 하긴 했는데
// 하나 하나 이해가 되긴 하지만, DFS BFS를 모두 적용해서 갑자기 하라 그러면 정말 쉽지 않았을 것 같다..
// 삼성 문제 이기도 하므로 계속 보기
