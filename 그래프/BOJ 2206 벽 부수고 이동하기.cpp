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


int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int arr[1001][1001];
int check[1001][1001][2];

int BFS(){
    queue<pair<pair<int, int>, int>>q;
    q.push({{0,0}, 1});
    check[0][0][1] = 1;
    // 세번째의 1은 벽을 뚫었는지 아닌지 확인하는 것이다.
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int wall = q.front().second;
        q.pop();
        
        if(x == n-1 & y == m-1){
            return check[x][y][wall];    // 끝날 경우 리턴한다.
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            
            if(arr[nx][ny] == 1 && wall){       // 1이고 wall이 아직 1일 경우
                check[nx][ny][wall-1] = check[x][y][wall] + 1;
                q.push({{nx, ny}, wall-1});
                // wall을 사용하여 1을 줄여준다.
                // x,y에서 nx,ny로 가는데 wall을 줄여주고 1을 늘려준다.
            }
            else if(arr[nx][ny] == 0 && check[nx][ny][wall] == 0){
                check[nx][ny][wall] = check[x][y][wall] + 1;
                q.push({{nx, ny}, wall});
            }   // 아직 arr가 0이고, nx,ny,wall도 아직 0으로 진행하지 않았을 경우
                // nx,ny,wall에 관하여 1늘려 주고 넣는다.
            
        }
        
    }
    
    return -1;
    // 위에서 리턴 되지 않을 경우 안되는 것이므로 -1을 출력하고 끝낸다.
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        string st;
        cin >> st;
        for(int j=0;j<m;j++){
            arr[i][j] = st[j] - '0';
        }
    }
    
    
    
    cout << BFS() << '\n';
    
    
    return 0;

}
