
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

int a[101];
int b[101];

bool check(int x1, int y1, int x2, int y2){
    if(x1 + x2 <= h && max(y1, y2) <= w)
        return true;
    if(y1 + y2 <= w && max(x1, x2) <= h)
        return true;
    // 둘은 크기가 다르므로, 옮겨지면 한계도 옮겨져야
    
    return false;
}
// 두개 더한 범위가 h보다 작고, 둘 중 최대가 w보다 작을 경우
// x1,y1 과 x2,y2도 바꾸어서 해본다.
// 둘 중 하나만 만족해서 true로 해줌 (x1,y1), (x2,y2) 둘 중 하나라도

bool turn(int x1, int y1, int x2, int y2){
    if(check(x1, y1, x2, y2))
        return true;            // 회전 xx
    if(check(y1, x1, x2, y2))
        return true;            // ox
    if(check(x1, y1, y2, x2))
        return true;            // xo
    if(check(y1, x1, y2, x2))
        return true;            // oo
    
    return false;
}
// 돌려서 check해서 가능하면 true

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> h >> w;
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(turn(a[i], b[i], a[j], b[j]))
                ans = max(ans, a[i] * b[i] + a[j] * b[j]);
        }
    }
    
    cout << ans;
    
    
    return 0;
}

// 돌리거나 그냥 넣어서 범위 안에 있어야 성립되는데, 이를 함수로 만들어서
// 돌려주고, 넣어주어 확인 해보면 간단하게 구할 수 있다.
// 최대값은 그냥 max로 해서 ans와 비교해주면 된다.

// 생각 많이 해보면 충분히 할 수 있는 문제이므로 비슷한 문제를 안보고 다시 풀어보아야 할것..!
