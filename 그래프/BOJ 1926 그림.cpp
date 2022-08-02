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


bool check[501][501];
int arr[501][501];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int, int>>q;
int num = 0;
int ans = 0;
int Max = 0;

void BFS(int a, int b){
    q.push({a, b});
    check[a][b] = true;
    int cnt = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(!check[nx][ny] && arr[nx][ny] == 1){
                check[nx][ny] = true;
                cnt++;
                q.push({nx, ny});
            }
        }
    }
    
    if(Max < cnt)
        Max = cnt;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!check[i][j] && arr[i][j] == 1){
                num++;
                BFS(i, j);
            }
        }
    }
    
    
    cout << num << '\n' << Max;
    
    return 0;

}



