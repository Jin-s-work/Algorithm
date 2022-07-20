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

bool check[110][110];
int arr[110][110];
//int dx_odd[6] = {-1,0,1,1,0,-1};
//int dy_odd[6] = {1,1,1,0,-1,0};
//int dx_even[6] = {-1,0,1,1,0,-1};
//int dy_even[6] = {0,1,0,-1,-1,-1};
// n = 3, (0,-1),(-1,0),(0,1), (1,-1), (1,0), (1,1)
// n = 2, (-1,-1),(-1,0),(-1,1), (0,1), (1,0), (0,-1)
// ??
int dx[2][6] = { {-1, 0, 1, 1, 0, -1}, {-1, 0, 1, 1, 0, -1} };
int dy[2][6] = { {0, 1, 0, -1, -1, -1}, {1, 1, 1, 0, -1, 0} };
// 이 부분을 바꾸니까 제대로 나온다.. 모디..
// 그냥 이렇게 해준다고 생각하자


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
        }
    }
    
    // 1인 부분에서 양 6개의 방향에 대해 조사하여 0이거나 범위를 벗어났을 경우 개수를 더해준다.
    // 하지만 둘러쌓여 있는 0의 경우에는 check를 통하여 넘거가여 개수를 더하지 않는다.
    // 로 풀면 되지 않을까...?
    
    queue<pair<int, int>>q;
    check[0][0] = true;
    q.push({0,0});
    // 처음의 0,0은 true로 하고 없애준다.
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<6;i++){
            int nx = x + dx[x % 2][i];
            int ny = y + dy[x % 2][i];
            // 짝수 홀수 각각 움직이는게 다르므로 이렇게 한다.
            // x % 2 로 하는 방법도 있다.
            
            if(nx < 0 || nx > m+1 || ny < 0 || ny > n+1)
                continue;
            // 넘으면 넘어가기
            
            if(check[nx][ny] || arr[nx][ny])
                continue;
            // check가 이미 true이거나 arr이 1일 때 넘어가기
            // ** 지나가려는 부분이 이미 못 넘어갈 경우는 그냥 넘어가고
            // 아닐 경우 true로 하고 큐에 넣어주기
            check[nx][ny] = true;
            q.push({nx, ny});
            
        }
    }
    
    int ans = 0;
    for(int x=1;x<=m;x++){
        for(int y=1;y<=n;y++){          // 여기서 h와 n을 잘못 썻다..
            if(arr[x][y] == 0)
                continue;
            // 0일 경우에는 넘어가고 1인 경우에만 진행
            for(int i=0;i<6;i++){
                int nx = x + dx[x % 2][i];
                int ny = y + dy[x % 2][i];
                
                if(check[nx][ny])
                    ans++;
                // check한 경우가 true일 경우 ans를 증가시켜준다.
                // 왜냐하면 움직인 값들이 아직 안 지나간 경우에 못지나가므로 더해준다.
                // 못가는 부분에서 선이 개수이므로 그만큼 더한다.
                
                // 체크를 확인해주는 것은 위에를 다 지나도 0인 경우를 막기 위해서..
                // 1->0이거나 1->바깥 의 경우만 true이다.
                // 예의 가운데 부분은 애초에 0이므로 check가 true인 적이 없어 nx,ny일 때 세지 않는다.
                // *********
            }
        }
    }
    
    cout << ans;
    
                           
    return 0;

}


