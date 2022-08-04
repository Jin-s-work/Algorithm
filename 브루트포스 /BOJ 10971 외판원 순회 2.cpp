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


int arr[11][11];
bool check[11];
int start;
int ans = MAX;

void DFS(int now, int cost, int num){       // 현재의 위치와 cost도 바꾸어가면서 넣어주어야
    if(num == n-1){
        if(arr[now][start]){        // 마지막에는 start로 와야해서 now에서 start로 갈 수 있어야한다.
            ans = min(ans, cost + arr[now][start]);
            return;
        }
    }
    
    for(int i=1;i<=n;i++){      // i에 대해서 파고들기
        if(arr[now][i] && !check[i]){
            // arr가 0이면 안되고 check도 아직 지나지 않은 경우에서
            check[i] = true;
            DFS(i, cost + arr[now][i], num+1); // cost에 대해서도 now->i로 가는 경우 더해주며 이어가기
            check[i] = false;
            // 끝났을 경우 false로 다시 해여 다른 경우를 돌려준다.
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
        }
    }
    
    for(int i=1;i<=n;i++){
        start = i;
        // 다시 돌아와야 하므로 start도 저장해놓고 이를 확인해주어야 한다.
        
        check[i] = true;
        DFS(i, 0, 0);
        check[i] = false;
        // false로 하여금 다시 초기화
    }
    
    cout << ans;
    
    return 0;

}

