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


int arr[101][101][101];
int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0,0,0,1,-1};

queue<pair<pair<int, int>, int>>q;
int Max = 0;

void BFS(){
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        
        q.pop();
        
        for(int i=0;i<6;i++){           // 다 제대로 했는데 이거 안바꿈..
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h)
                continue;
            
            if(arr[nx][ny][nz] == 0){      // -1을 굳이 사용하지 않고 0일때만 골라서 더해주면 된다..
                arr[nx][ny][nz] = arr[x][y][z] + 1;
                q.push({{nx, ny}, nz});
            }
            
        }
        // 그냥 찾고 그 arr에 날자수를 알 수 있게 더해나가고 지나가는 q를 push해주는 단순한 BFS
        
    }
    
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m >> h;
    for(int k=0;k<h;k++){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 1){
                    q.push({{i, j}, k});
                }
                // 처음부터 큐에 i,j를 넣어 토마토가 있는 부분을 큐에 넣어준다고 생각하면 된다.
            }
        }
    }
    
    BFS();
    // 현재 있는 토마토에 관해서 큐에 있는 위치 정보를 사용한다.
                           
    for(int k=0;k<h;k++){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j][k] == 0){// BFS가 끝났는데 아직 하나라도 0이 남아있다면 -1을 출력하고 끝
                    cout << "-1" << '\n';
                    return 0;
                }
                if(Max < arr[i][j][k])         // 전체를 탐색하면서 제일 큰 arr[i][j]를 찾아본다.
                    Max = arr[i][j][k];
                }
            }
        }
    cout << Max - 1;
                           // 처음에 arr[x][y]의 시작이 1이기에 1을 빼주어야 한다.
                           
                           
    return 0;

}


