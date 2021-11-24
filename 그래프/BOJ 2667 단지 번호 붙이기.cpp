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


char arr[101][101];
int ans = 0;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int, int>>q;
int check[101][101];
vector<int>v;

void BFS(int a, int b){
    q.push({a, b});
    check[a][b] = 1;
    ans++;
    // 이때 ans를 증가시켜줌
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx <= 0 || nx > n || ny <= 0 || ny > n)
                continue;
            // 범위넘으면 그냥 continue
            
            if(check[nx][ny] == 0 && arr[nx][ny] == 1){
                check[nx][ny] = 1;
                q.push({nx, ny});
                ans++;
            }
        }   // 다음의 path가 0이어서 새로 방문하라 수 있고, 다음이 이동할 수 있는 1일 경우
        
        
    }
    
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
            arr[i][j] -= '0';
        }
    }
    // char를 받아서 숫자로 써야하기에 '0'을 빼주어야 숫자가 된다.
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j] == 1 && check[i][j] == 0){
                // arr가 1이라 이동이 가능하고, check도 0이라 방문하지 않았을 경우
                BFS(i, j);
                v.push_back(ans);
                ans = 0;
                // BFS를 해주고, 그에 따른 ans를 벡터에 넣어주고, 초기화 해준다.
                // 초기화 하는 것은 새로운 ㅁns를 찾기 위하여
            }
        }
    }

    sort(v.begin(), v.end());
    
    cout << v.size() << '\n';
    for(auto k : v)
        cout << k << '\n';
    
    
    
    return 0;

}



