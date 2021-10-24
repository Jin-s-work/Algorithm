
#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>
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
int h;


int arr[1001][1001];
int ans;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int s;
    cin >> s;
    
    
    queue<pair<int, int>> q;
    
    q.push({1, 0});     // 처음은 이모티콘 1, 클립보드 0
    arr[1][0] = 1;      // 한번 하였으므로 1로 해준다.
    
    int ans = 100001;        // 제일 크게 해놓고 비교
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x == s){             // 계속 하다가 x가 s가 될 경우 제일 작은 arr[x][y]를 기준으로 ans한다.
            ans = min(ans, arr[x][y]);
        }
        
        if(!arr[x][x]){         // arr[x][x]는 arr[x][y]에서 '1번'을 한 경우 이므로 1을 더한다.
            arr[x][x] = arr[x][y] + 1;
            q.push({x, x});     // x,x로 바뀌므로 push 해준다.
        }
        
        if(x+y <= s && !arr[x+y][y]){    // arr[x+y][y]가 아직 가지 않고, x+y가 s가 아직 안되었을때
            arr[x+y][y] = arr[x][y] + 1;    // 왜냐하면 x+y가 s를 넘으면 안된다.
            q.push({x+y, y});     // arr[x][y]에서 '2번'을 수행하면 [x+y][y]가 된다.
        }
        
        if(x >= 1 && !arr[x-1][y]){     // x-1이 1 이상이어야 한다.
            arr[x-1][y] = arr[x][y] + 1;    // arr[x][y]에서 삭제 이므로 1개 줄임
            q.push({x-1, y});
        }
        
    }
    
    cout << ans - 1;
    // 지나간 경우 1로 설정해 주었으므로 이를 다시 줄여줘야 한다.
    
    
    return 0;
}

// 이모티콘, 클립보드로 보통 생각을 하면 된다.

// 1. 복사 할 경우 (x, y)에서 (x, x)
// 2. 붙여 넣을 경우 (x, y)에서 (x+y, y)
// 3. 지울 경우 (x, y)에서 (x-1, y)

// && 의 순서를 다르게 해서 틀림 -> short circuit evaulation
