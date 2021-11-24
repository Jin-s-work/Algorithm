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


int arr[1001][1001];
int ans = 0;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int, int>>q;
vector<int>v;
int Max = 0;

void BFS(){
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx <= 0 || nx > n || ny <= 0 || ny > m)
                continue;
            // 범위넘으면 그냥 continue
            
            if(arr[nx][ny] == 0){
                arr[nx][ny] = arr[x][y] + 1;
                q.push({nx, ny});
                // 이동한 좌표가 0일 경우, 넘어가면서 전의 좌표에서 1을 더해줌
                // 이동한 좌표를 넣어준다.
            }
            
        }
        
        
    }
    
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> m >> n;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1)
                q.push({i, j});
            // 1일 경우 q에 넣어서 시작부분을 정해줌
        }
    }
    
    BFS();
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j] == 0){
                cout << "-1" << '\n';
                return 0;
                // 다 했는데도 0이 남아있으면 -1을 출력하고 끝
            }
            
            if(Max < arr[i][j])
                Max = arr[i][j];
        }
    }

    cout << Max - 1;
    // 1일 때 1씩 더해주므로, 1을 마지막에 빼줘야 한다.
    
    
    return 0;

}



