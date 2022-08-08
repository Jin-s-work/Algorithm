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


int arr[101][101];
int dist[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int, int>>q;

void Dijkstra(int m, int n, int a, int b){
    q.push({a, b});
    dist[a][b] = 0;
    // 처음에 0으로 시작한다.
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            
            if(arr[nx][ny] == 1){
                if(dist[nx][ny] > dist[x][y] + 1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
                // 다음에 움직이는 곳이 1일 경우에 dist가 전의 dist에 1을 더한 것보다 클 경우에
                // 옮겨간다.
                
                // 이러면서 더 작은 값이 들어올 경우 갱신해주면서 최솟값을 찾는 것이다.
            }
            else if(arr[nx][ny] == 0){
                if(dist[nx][ny] > dist[x][y]){
                    dist[nx][ny] = dist[x][y];
                    q.push({nx, ny});
                }
                // 다음에 움직일 곳이 0인 경우에는
                // 개수가 똑같으므로 같은 dist를 옴겨가며 이동한다.
            }
        }
    }
}


int main(){
    
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    설마 이거 밑에 scanf 써서 이거 쓰면 안되나..
    
    cin >> m >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", & arr[i][j]);
            dist[i][j] = MAX;
            // 여기서 다 MAX로 만들어놓는다.
        }
    }
    
    Dijkstra(m, n, 0, 0);
    
    cout << dist[n-1][m-1];
    
    
    return 0;
    
}

