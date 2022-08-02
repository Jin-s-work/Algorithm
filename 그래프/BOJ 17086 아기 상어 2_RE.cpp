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


int arr[51][51];
int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,1,-1,0,0,1,-1};
queue<pair<int, int>>q;
int ans = 0;

void BFS(){
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            
            if(arr[nx][ny] == 0){       // 0일 경우에만 퍼져나간다.
                q.push({nx, ny});
                arr[nx][ny] = arr[x][y] + 1;
            }   // 1씩 더해가며 거리값을 넣어준다.
        }
    }
    
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                q.push({i, j});
            }
        }
    }
    
    BFS();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ans < arr[i][j])
                ans = arr[i][j];
            // 제일 큰 값을 찾는다.
        }
    }
    
    cout << ans - 1;
    // 상어가 들어갈 때 1로 들어가므로 1을 빼주어야 원래 값이 된다.
    
    
    return 0;

}


