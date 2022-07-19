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

bool check[51][51];
int arr[51][51];
vector<pair<int, int>>v;
// 인구 계산을 해주기 위해서 v벡터에도 위치를 넣어준다.

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int cnt = 0;
int sum = 0;
int ans;
bool flag = false;
// sum, cnt는 평균을 구하기 위해서, flag은 true false 판별하기 위해서

void BFS(int a, int b){
    queue<pair<int, int>>q;
    q.push({a, b});
    v.push_back({a, b});
    check[a][b] = true;
    sum += arr[a][b];
    cnt++;
    // 처음에 한개를 넣어준 것이므로 cnt도 증가시켜줌
    
    // 처음의 a, b도 큐와 벡터에 넣어주고 true 표시도 하고 지났으므로 sum에 넣어줌
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if(check[nx][ny])
                continue;
            // 이미 다음 넘어가는 부분이 이미 true일 경우 넘어가도 된다.
            
            if((abs(arr[nx][ny] - arr[x][y]) >= l) && (abs(arr[nx][ny] - arr[x][y]) <= r)){
                check[nx][ny] = true;
                cnt++;
                sum += arr[nx][ny];
                q.push({nx, ny});
                v.push_back({nx, ny});
                // 처음 들어오는 a,b와 같이 위의 조건이 만족되면 다음의 좌표에 대하여
                // true 표시 해주고, 숫자늘려주고, 큐와 벡터에 좌표를 넣어준다.
                // 좌표가 true일 경우 교류 가능 한 부분 이라는 것.. 굳이 4중 배열로 할 필요가 없었다.
            }
                
        }
    }
    
    if(v.size() >= 2){
        int av = sum / cnt;
        
        for(int i=0;i<v.size();i++){
            int xx = v[i].first;
            int yy = v[i].second;
            arr[xx][yy] = av;
        }
        // v에 있는 즉 교환가능한 모든 수에 관하여 합들의 평균을 넣어 바꾸어 준다.
        
        flag = true;
        // 했으므로 true로 한다.
    }
    
    v.clear();
    sum = 0;
    cnt = 0;
    // 둘은 초기화한다.
    
    // 연결된 모든 나라들의 교류가 이루어지면 다시 처음으로 돌아가서 시작한다.
    // 큐는 while 문을 빠져나와 아무것도 없으므로 다시 할 수 있음

}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    // l과 r을 전역변수로 해야 했는데 여기다 쓴게 잘못이었다..
    cin >> n >> l >> r;
    
    ans = 0;
    sum = 0;
    cnt = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    while(1){
        memset(check, false, sizeof(check));
        flag = false;
        // 돌때마다 false로 하고 다시 돌려야 한다.
        // 시간 이 지날때마다 false로 시작한다.
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!check[i][j])
                    BFS(i, j);
            }
        }
        // 아직 방문되지 않은 i,j에 관하여 BFS를 진행한다.
        
        if(flag)
            ans++;
        else
            break;
        // flag가 참일 경우 즉 교환이 이루어질 경우 ans를 늘려주고 false가 나올 경우 끝내준다.
        
        // 즉 교환이 일어날 경우 true가 되어 움직이는데 그렇지 않을 경우 멈춰줄 수 있도록 한다.
    }
    
    cout << ans;
    
                           
    return 0;

}


