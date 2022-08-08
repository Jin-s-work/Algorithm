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


int arr[1001][1001];
bool check[1001][1001][10];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<pair<int, int>, pair<int, int>>>q;


// 원래 해보려는 코드가 복잡해서 그냥 {{}, {}}의 큐 구조로 보든 num과 wall을 같이 queue에 넘겨주며 고려하기
void BFS(){
    q.push({{0, 0}, {1,0}});
    check[0][0][0] = true;
    // 처음 x,y는 0,0이고, num,wall은 1,0으로 시작한다.
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int num = q.front().second.first;
        int wall = q.front().second.second;
        q.pop();
        
        if(x == n-1 && y == m-1){
            cout << num << '\n';
            return;
            // 범위가 끝날 경우 num을 출력하면서 끝낸다.
        }
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            
            if(check[nx][ny][wall] == false){       // 아직 방문하지 않는 경우
                if(arr[nx][ny] == 0){           // 아무것도 없을 경우에 방문함을 표시하고
                    check[nx][ny][wall] = true; // num만 늘려주면서 queue에 저장한다.
                    q.push({{nx, ny}, {num+1, wall}});
                }
                else if(arr[nx][ny] == 1){      // 벽을 지날 경우
                    if(wall < k){               // 아직 wall이 k보다 작을 경우에 위와 같이 해주고
                        check[nx][ny][wall+1] = true;       // num,wall 모두 늘려준다.
                        q.push({{nx, ny}, {num+1, wall+1}});
                    }
                }
            }
        }
    }
    // 적고 보니 되게 간단한게 이렇게 해도 되나..?
    // BFS의 경우에 점차 움직이며 진행할 텐데, 이럴 경우 움직이며 제일 최소인 값들이 먼저 올 수 밖에 없어
    // check가 먼저 true로 할 경우가 가장 작은 값이 될 수 밖에 없다.
                               
    cout << -1;
}


int main(){
    
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    설마 이거 밑에 scanf 써서 이거 쓰면 안되나..
    
    cin >> n >> m >> k;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", & arr[i][j]);
            // 여기서 다 MAX로 만들어놓는다.
        }
    }
    
    BFS();
    
    
    return 0;
    
}

