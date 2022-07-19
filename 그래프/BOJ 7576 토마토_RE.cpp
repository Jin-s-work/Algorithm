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


int arr[1001][1001];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

queue<pair<int, int>>q;
int check[1001][1001];
int Max = 0;

void BFS(){
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            
            if(arr[nx][ny] == 0){      // -1을 굳이 사용하지 않고 0일때만 골라서 더해주면 된다.. 그렇군
                arr[nx][ny] = arr[x][y] + 1;
                q.push({nx, ny});
            }
            
        }
        // 그냥 찾고 그 arr에 날자수를 알 수 있게 더해나가고 지나가는 q를 push해주는 단순한 BFS
        
    }
    
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                q.push({i, j});
            }
            // 처음부터 큐에 i,j를 넣어 토마토가 있는 부분을 큐에 넣어준다고 생각하면 된다.
        }
    }

    BFS();
    // 현재 있는 토마토에 관해서 큐에 있는 위치 정보를 사용한다.
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 0){         // BFS가 끝났는데 아직 하나라도 0이 남아있다면 -1을 출력하고 끝
                cout << "-1" << '\n';
                return 0;
            }
            if(Max < arr[i][j])         // 전체를 탐색하면서 제일 큰 arr[i][j]를 찾아본다.
                Max = arr[i][j];
        }
    }
    
    cout << Max - 1;
    // 처음에 arr[x][y]의 시작이 1이기에 1을 빼주어야 한다.
    
    
    return 0;

}


