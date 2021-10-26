
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


int arr[1001][1001];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans = 0;

char ch[1001][1001];
bool check[1001][1001] = {false};
int sx, sy;
int ex, ey;

queue<pair<int, int>>q;

int BFS(){
    
    q.push({sx, sy});
    arr[sx][sy] = 0;
    // 처음 지점을 queue에 넣어주고, arr에 그 지점을 0으로 해준다.
    
    while(!q.empty()){
        
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            // 각각의 queue에 빼서 x,y를 해서 해본다.
            
            for(int i=0;i<4;i++){
                for(int j=1;j<=k;j++){      // 이동하는 좌표를 1-k로 해서 하나씩 다 해본다.
                    int nx = x + dx[i] * j;
                    int ny = y + dy[i] * j;
                    
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || ch[nx][ny] == '#' || arr[nx][ny] < arr[x][y] + 1)
                        break;
                    // 범위를 넘거나, 다음 좌표가 #이거나,
                    // arr[nx][ny] = arr[x][y] + 1 일 경우에도 탐색을 해주어야 한다.
                    // 따라서 arr[nx][ny] <= arr[x][y] + 1이 아니다.
                    // 밑의 설명에서 말한 경우와 같다고 보면 된다.. nx가 arr+1보다 작을 때 그래서 break
                    // 정리하자면 다음 arr가 지금보다 1 더한것의 이상일 경우 탐색한다.

                    
                    if(arr[nx][ny] == MAX){
                        arr[nx][ny] = arr[x][y] + 1;
                        q.push({nx, ny});
                    }
                    // 만약 움직인 부분이 아직 안변한 부분일 경우 진행한 것에서 1더해준 것으로 갱신해주고
                    // 그 부분부터 진행하므로 queue에 push해준다.
                    
                    // 즉, 이 if문의 의도는 방문하지 않은 곳을 먼저 찾아서 탐색하는 것이다.
                    // MAX일 경우를 찾아서 탐색 해버림.
                }
            }
            
            
        }
        
        
    
    if(arr[ex][ey] == MAX)
        return -1;          // 마지막 arr가 바뀌지 않고 그냥 MAX이면 그냥 -1을 리턴
    else
        return arr[ex][ey];   // 바뀌었을 경우 바뀐 arr를 출력 해줌 그게 답임.
    
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m >> k;
    
    for(int i=0;i<n;i++){
        cin >> ch[i];               // char로 해서 ch[i]만 받으면 ch[i][j]가 각각 문자열이 된다.
        for(int j=0;j<m;j++){
            arr[i][j] = MAX;        // 모든 arr를 최대로 해준다.
        }
    }
    
    cin >> sx >> sy >> ex >> ey;
    
    sx--;
    sy--;
    ex--;
    ey--;           // 0,0을 기준으로 하므로 맞추어 주려면 1씩 줄여야 한다.
    
    ans = BFS();
    
    if(ans == -1){              // 그냥 -1이 출력 될 경우 -1로
        cout << "-1" << '\n';
        return 0;
    }
    
    cout << ans;
    
    
    
    return 0;
}

// 이동할 방향을 하나 고르고, 그 방향으로 (1-k)개 만큼 빈칸을 이동한다.
// 여기서 최소 시간을 구하면 된다.

// k는 입력에서 주어지므로, 그것을 토대로 하면 된다.

// 그렇지만 입력은 1000*1000이고, 최대 이동 칸수는 1000이므로 모두 확인하면 1000^3으로 시간 초과다.
// 따라서 방문체크를 해주면서 해주어야 한다.

// n인 지점에서 탐색 할 경우 n인 지점이나 n보다 작은 지점을 만나면 그 이후의 길은 n인 지점에서 잇는것이 아니라
// 해당 지점에서 이어나가는 것이 최소로 하기에 더 좋다.

// 즉 11111로 진행해서 가다가 2를 만났을 경우 2에서 3으로 바꾸고 하는 것 보다
// 1111에서 2를 만나도 무시하고 그냥 다음 2로 진행하는 것이 더 최소를 구할 수 있는 것이다.

