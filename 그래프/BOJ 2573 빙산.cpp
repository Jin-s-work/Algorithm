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


int arr[301][301];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool check[301][301];

void BFS(int a, int b){
    queue<pair<int, int>>q;
    q.push({a,b});
    check[a][b] = true;
    // 처음 시작 부분에 대해 큐에 넣고 true로 한다.
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(check[nx][ny])
                continue;
            // 이미 큐에 있는 경우 (즉 빙하인 경우)에도 넘어간다.
            
            if(arr[nx][ny] == 0){
                if(arr[x][y] == 0){
                    arr[x][y] = 0;
                }
                else{
                    arr[x][y]--;
                }
            }
            // nx,ny가 0일 경우 x,y가 0이면 그냥 0이고 아닐 경우 줄여 준다.
            else{
                check[nx][ny] = true;
                q.push({nx, ny});
            }
            // 아닐 경우 빙하인 경우이므로 nx,ny를 true로 해주고 큐에 넣어준다.
        }
        
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    
    int ans = 0;
    int glacier = 0;
    while(1){
        glacier = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j] != 0 && check[i][j] == false){
                    BFS(i, j);      // 빙하이고 아직 방문하지 않았을 때 거기서부터 BFS를 진행한다.
                    glacier++;      // 그러고 섬의 개수를 늘린다.
                }                   // 한 번 다 돌았을 경우 glacier 자체가 증가하는 것
            }     // ** 한 번 더 돌 수 있을 경우 즉 false인데 0이 아닌 경우가 있으면 glcier 증가 **
        }
        
        if(glacier >= 2){           // 두개 이상으로 나뉘면 답을 출력한다.
            cout << ans << '\n';
            return 0;
        }
        if(glacier == 0)            // 빙하가 0개가 되면 끝내준다.
            break;
        memset(check, 0, sizeof(check));    // check는 다시 다 0으로 만들어준다.
        
        ans++;

        
    }
    
    cout << 0 << '\n';
    
    return 0;

}
