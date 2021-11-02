
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
int h, w;

ll a, b;
ll ans = 0;

void find(ll num){
    
    if(num > b)
        return;
    
    if(num >= a && num <= b)
        ans++;
    
    find(num * 10 + 4);
    find(num * 10 + 7);
    // 각각 4오아 7부터 시작해서 이 두 함수를 재귀적으로 하면 4747, 477 과 같은 4와 7로만 이루어지게 할 수 있다
    // 범위가 넘으면 끝내준다.
    
    // 전에는 함수내에서 큰수를 줄여가며 했는데, 이와 같이 재귀함수로
    // 위로 올라가면서 찾다가 범위를 넘으면 멈추는게 나을듯..?
}

// 시간 초과를 막기 위하여 for문으로 일일이 하는 것보다는 재귀로 해보아야겠다.

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> a >> b;
    
    find(4);
    find(7);
    // 4와 7부터 시작한다.
    
    cout << ans;

    
    return 0;
}

