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


char arr[101][101];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int, int>>q;
int path[101][101];

void BFS(int a, int b){
    q.push({a, b});
    path[a][b]++;
    
    
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
            
            if(path[nx][ny] == 0 && arr[nx][ny] == 1){
                path[nx][ny] = path[x][y] + 1;
                q.push({nx, ny});
            }
        }   // 다음의 path가 0이어서 새로 방문하라 수 있고, 다음이 이동할 수 있는 1일 경우
        
        
    }
    
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
            arr[i][j] -= '0';
        }
    }
    // char를 받아서 숫자로 써야하기에 '0'을 빼주어야 숫자가 된다.
    
    BFS(1, 1);
    // 1,1부터 시작한다.
    
    cout << path[n][m];
    
    
    
    
    return 0;

}



