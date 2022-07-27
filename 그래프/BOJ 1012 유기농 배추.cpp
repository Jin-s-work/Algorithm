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

int arr[51][51] = {0};
bool check[51][51] = {0};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void DFS(int y, int x){
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
        
        // arr가 1이고 check가 아직 방문 하지 않은 경우 DFS로 들어간다.
        if(arr[ny][nx] && !check[ny][nx]){
            check[ny][nx] = 1;
            DFS(ny, nx);
        }
    }
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> t;
    while(t--){
        cin >> m >> n >> k;
        
        memset(arr, 0, sizeof(arr));
        memset(check, 0, sizeof(check));
        
        int ans = 0;
        for(int i=0;i<k;i++){
            int a, b;
            cin >> a >> b;
            
            arr[b][a] = 1;
            // 이게 순서가 왜 거꾸로 인지 아직도 잘 모르겠다....
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j] && !check[i][j]){
                    ans++;
                    check[i][j] = 1;
                    DFS(i, j);
                }   // DFS 안의 구성처럼 1이고 check가 아직 방문하지 않았을 때 늘려주고
            }       // 진행하면서 ans를 늘려 덩어리 개수를 구해준다.
        }
        
        cout << ans << '\n';
    
    }
    
    
    return 0;

}


