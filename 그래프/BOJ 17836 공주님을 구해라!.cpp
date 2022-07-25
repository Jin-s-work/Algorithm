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
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool check[101][101];
bool check2[101][101];


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m >> t;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    
    queue<pair<pair<int, int>, bool>> q;
    q.push({{0,0}, false});
    check[0][0] = true;
    
    bool prin = false;
    
    for(int k=0;k<=t;k++){
        
        int tmp = q.size();
        for(int j=0;j<tmp;j++){
            int x = q.front().first.first;
            int y = q.front().first.second;
            bool flag = q.front().second;
            q.pop();
            
            if(arr[x][y] == 2)
                flag = true;
            // 2일 경우 flag가 true로 바뀐다.
            if(x == n-1 && y == m-1){
                prin = true;
                break;
                // 만나면 끝
            }
            
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if(flag && check2[nx][ny])
                    continue;
                // 소드가 있고, check가 nx,ny가 true면 이미 지나갔으므로 넘어감
                if(!flag && check[nx][ny])
                    continue;
                // 소드가 없고, check가 true여서 이미 자나갔을 경우에도 그냥 넘어간다.
                if(!flag && arr[nx][ny] == 1)
                    continue;
                // 소드가 없는데 벽이 있으면 못건넘
                
                if(flag)
                    check2[nx][ny] = true;
                else
                    check[nx][ny] = true;
                // 위를 다 넘어왓을 경우 flag가 있으면 check2를 체크하고 아닐 경우 check를 true로 해줌
                
                q.push({{nx, ny}, flag});
                
            }
        }
        
        if(prin){
            cout << k << '\n';
            break;
        }
        // t 안에 true가 되면 시간을 출력한다.
    }
    
    if(!prin)
        cout << "Fail" << '\n';
    
    
    return 0;

}
