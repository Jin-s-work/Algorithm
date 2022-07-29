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


int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};
int arr[51][51];
bool check[51][51];
int ans = 0;

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    check[x][y] = true;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0;i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            
            if(!check[nx][ny] && arr[nx][ny]){
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        
    }
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    while(1){
        
        // 처음에 여기서 n,m을 초기화 해줘서 틀린 것 같다.
        // 그냥 알아서 하게 내비둬야 함
        cin >> n >> m;
        
        if(n == 0 && m == 0)
            break;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin >> arr[i][j];
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!check[i][j] && arr[i][j]){
                    ans++;
                    BFS(i, j);
                }
                // 방문하지 않고 1일 경우에 계속 들어간다.
            }
        }
        
        cout << ans << '\n';
        
        memset(check, false, sizeof(check));
        memset(arr, false, sizeof(arr));
        
        ans = 0;
        
        
    }
    
    
    
    
    return 0;

}


