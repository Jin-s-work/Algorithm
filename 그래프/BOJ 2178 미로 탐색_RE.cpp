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

// control i
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
char arr[101][101];
int path[101][101];
queue<pair<int, int>>q;


void BFS(int a, int b){
    q.push({a, b});
    path[a][b]++;
    // 표시
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // x, y의 각 방향을 위하여 4번 써준다.
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx <= 0 || nx > n || ny <= 0 || ny > m)
                continue;
            
            if(path[nx][ny] == 0 && arr[nx][ny] == 1){  // 다음으로 이동하는 path가 아직 0이고,
                path[nx][ny] = path[x][y] + 1;          // 그의 arr가 1일 경우 (이동 가능)
                q.push({nx, ny});
                // path[nx][ny]에서는 이제까지 움직인 길이 만큼을 더해준다.
            }
        }
        
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
            // char로 받아서 '0'을 빼주어서 int인 숫자로 씀
        }
    }
    // string으로 그냥 받아서 하는 방법도 있지만 어차피 이래도 stoi를 써야 하기에 이렇게 쓰는게 편하긴 할듯
    
    BFS(1,1);
    // 1, 1을 처음으로 한다.
    
    cout << path[n][m];
    
    
    return 0;

}



