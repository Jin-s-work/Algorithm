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



bool check[26][26];
char arr[26][26];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int, int>>q;
vector<int>ans;
int num = 0;

void BFS(int a, int b){
    q.push({a, b});
    check[a][b] = true;
    num++;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx > n || nx <= 0 || ny > n || ny <= 0)
                continue;
            // 바보 같이 범위 제대로 안함
            
            if(check[nx][ny] == 0 && arr[nx][ny]){
                num++;
                q.push({nx, ny});
                check[nx][ny] = 1;
                // nx,ny를 1로 체크 해주어야 한다. 지났으므로
            }
            
        }
        
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
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j] == 1 && check[i][j] == 0){
                BFS(i, j);
                ans.push_back(num);
                num = 0;
                // num을 계속 갱신해준다. 이러면 그냥 전역변수로 써도 가능
            }
        }
    }
    // 다 풀었는데 BFS를 메인함수에서 구현하지 못했다..
    // 모든 arr 인덱스에 대해서 맞을 경우 거기서 BFS를 진행하여 수를 구해 답 벡터에 넣어준다.
    // 한번 이미 했을 경우 check에 true로 되어있기에 중복되지 않을 것이다.
    
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << '\n';
    for(auto k : ans){
        cout << k << '\n';
    }
    
    
    
    return 0;

}
