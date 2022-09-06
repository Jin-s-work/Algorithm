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
#define mod 1000000000
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


int arr[301][301];

void DFS(int r){
    if(r == 0)
        return;
    
    // 더 작은 수에 대하여 /2 %2 해서 더해준다.
    int depth = min(n, m) / 2 + min(n, m) % 2;
    for(int start = 0; start < depth; start++){
        int x = start;
        int y = start;
        int pre = arr[x][y];
        
        // left
        while(x < n - 1 - start){    // x가 n - (start + 1) 일때 즉 왼쪽에 있을 때
            int next = arr[x+1][y];  // next에 [x+1][y]를 저장해놓고,
            arr[x+1][y] = pre;       // pre를 밑으로 옮겨준다.
            pre = next;              // 그러고 pre에는 next로 바꾸어서 x를 넘어간다.
            x++;            // x를 늘리고 왼쪽의 범위 안에서 계속 늘려준다.
        }
        // bottom
        while(y < m - 1 - start){
            int next = arr[x][y+1];
            arr[x][y+1] = pre;
            pre = next;
            y++;
        }
        // right
        while(x >= start + 1){      // 오른쪽에서는 위로 올라가므로 x가 start + 1 보다 클 때만
            int next = arr[x-1][y];
            arr[x-1][y] = pre;
            pre = next;
            x--;                    // x는 줄어든다.
        }
        // up
        while(y >= start + 1){      // 위에서도 y는 왼쪽으로 이동하므로 그보다 작아지면 안댐
            int next = arr[x][y-1];
            arr[x][y-1] = pre;
            pre = next;
            y--;                    // y도 줄어든다.
        }
    }
    
    DFS(r-1);
    // r 횟수만큼 또 DFS로 들어간다.
}


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r;
    cin >> n >> m >> r;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
     
    DFS(r);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    
    
   
    return 0;
    
}
