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

int arr[110][110];
queue<pair<int, int>>q;

int dy[2][6] = { {0, 1, 0, -1, -1, -1}, {1, 1, 1, 0, -1, 0} };
int dx[2][6] = { {-1, 0, 1, 1, 0, -1}, {-1, 0, 1, 1, 0, -1} };
bool check[110][110];
// 짝수인 경우에는 (+1, -1), (+1, +1)이 불가능하다.
// 홀수 인 경우에는 (-1, -1), (-1, +1)이 불가능하므로 순서대로 둘만 없게 한다.


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> w >> h;
    
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> arr[i][j];
        }
    }
    
    queue<pair<int, int>> q;
    check[0][0] = true;
    q.push({0,0});
    // 처음의 0, 0은 true로 하고 없애줌
    
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<6;i++){
            int nx = x + dx[x % 2][i];
            int ny = y + dy[x % 2][i];
            // 육각형이므로 움직이는 것이 다르다.
            // 그렇지만 x에 따라서 달라지므로 첫 배열을 x % 2 로 한다.
            if(nx < 0 || nx > h+1 || ny < 0 || ny > w+1)
                continue;
            /// 범위를 한 칸 씩 더 크게 해준다.
            if(check[nx][ny] || arr[nx][ny])
                continue;
            // check가 true이거나 arr이 1일 경우 넘어간다.
            
            // 아닐경우 true로 해주고 큐에 넣어준다.
            check[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    // 바깥 테두리 육각형을 칠하는 과정
    
    int ans = 0;
    for(int x=1;x<=h;x++){
        for(int y=1;y<=w;y++){
            if(arr[x][y] == 0)
                continue;
            for(int i=0;i<6;i++){
                int nx = x + dx[x % 2][i];
                int ny = y + dy[x % 2][i];
                
                if(check[nx][ny])
                    ans++;
                // 만약 check가 true일 경우라면 ans를 증가시켜준다.
                // 즉 움직인 값들이 아직 안지나갔을 경우 못지나가므로, 그 면에 대해서 1씩 더해준다.
                // 그러면 못가는 부분에 대해서 선이 곧 개수이므로, 그를 더해준다.
            }
        }
    }
    // 사이사이를 칠하는 과정
    
    cout << ans;
    
    return 0;

}

