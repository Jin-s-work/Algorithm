
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

int arr[21][21];
int check[21][21];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int a, b;

int fishnum = 0;        // 먹은 물고기의 수
int dist_sum = 0;       // 이동 거리의 합

int catchfish = 0;      // 잡을 수 있는 물고기 수     이것이 BFS 돌렸는데도 0이면 끝난다.
int min_dist = 987654321;   // 가장 가까운 물고기
int babysize = 2;       // 아기 상어의 사이즈

struct pos{
    int x;
    int y;
    int cnt;
};                  // 좌표와 수를 저장해주는 구조체

queue<pos>q;        // 와 같은 형태의 큐를 만든다.

bool inside(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < n)
        return true;
    else
        return false;
}
// 안에 있으면 true 아니면 false

void BFS(){
    min_dist = 987654321;       // 처음은 제일 크게 임의로 만들어준다.
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int num = q.front().cnt;
        
        q.pop();        // 각각의 큐마다 뽑아서 저장해주고 pop한다.
        
        check[x][y] = num;      // 횟수를 check 좌표에 저장시켜준다.
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 이동하는 좌표가 범위 안에 있고, num이 0이고, 상어보다 작은 사이즈를 가질 경우
            if(inside(nx, ny) && check[nx][ny] == 0 && arr[nx][ny] <= babysize){
                if(arr[nx][ny] < babysize && arr[nx][ny] != 0){
                    if(arr[nx][ny] > 0)
                        arr[nx][ny] *= -1;
                    // arr가 0이 아니고 아기 상어 크기보다 작을 경우
                    // 음수로 바꾸어서 표시해준다.
                    
                    
                    // 잡을 수 있는 물고기 수를 증가시켜주고
                    catchfish++;
                    if(num + 1 < min_dist)      // num + 1 이 최소 거리보다 작다면
                        min_dist = num + 1;     // num + 1을 고쳐준다.
                    
                }
                check[nx][ny] = num + 1;
                q.push({nx, ny, num + 1});
            }   // check 배열에 num + 1을 넣어주고 큐에 push해준다.
        }
        
    }
}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            
            if(arr[i][j] == 9){
                a = i;
                b = j;
                arr[i][j] = 0;
            }                   // 아기 상어의 위치를 찾으면 위치를 a,b에 저장해주고,
        }                       // 원래 있던 자리는 0으로 초기화해준다.
    }
    
    int flag = 0;           // 처음 플래그는 0으로 한다.
    while(1){
        check[a][b] = 1;        // 처음 아기 상어의 위치를 1로 넣는다.
        q.push({a, b, 1});      // 그러고 좌표와 num을 1로 넣어주고
        BFS();                  // BFS를 돌려준다.
        
        if(catchfish == 0)      // 만약 잡을 수 있는 고기가 0이면 멈추고 나온다.
            break;
        
        // 가장 가까운 거리에 먹을 수 있는 고기는 check 배열 중에 min_dist 값이다.
        // 그리고 거리가 가장 가까이 있다면 위에 있고 가장 왼쪽에 있는 것을 먹는다.
        // 그래서 for문을 사용해서 0-n 0-n으로 체크해준다.
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(check[i][j] == min_dist && arr[i][j] < 0){
                    fishnum++;
                    a = i;
                    b = j;
                    arr[i][j] = 0;
                    // check와 min_dist가 같고 arr가 0보다 작을 경우 (이는 BFS에서 -1로 표기)
                    // 그 위치를 a,b에 다시 저장해주고, arr에 0으로 넣는다. (물고기를 없앰)
                    
                    dist_sum += min_dist - 1;
                    flag = 1;
                    // 이동 거리를 더해준다.
                    // (이걸 할 경우 flag를 true로 바꾸어줌)
                    
                    if(fishnum == babysize){
                        fishnum = 0;        // 먹은 물고기 수와 상어 사이즈 크기가 같다면
                        babysize++;         // 상어가 +1 커진다.......
                    }
                    break;
                    
                }
            }
            if(flag == 1)       // 위의 for문에서 if도 성립하면 flag가 1이므로 break
                break;
        }
        flag = 0;
        catchfish = 0;
        // 잡을 수 있는 물고기도 0으로 다시 초기화 시켜줌
        memset(check, 0, sizeof(check));
        // 방문 배열을 초기화 시켜준다.
        // 그러고 break가 나올 때 까지 돌림
    }
    
    
    cout << dist_sum;
    // 최소 거리를 구하는 것
    
    return 0;
}


// 처음의 상어 크기는 2이다.
// 자기보다 큰 물고기 칸은 못 지나간다.
// 먹을 수 있는 물고기가 많다면
