
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


ll dp[51][51][51][51];
ll re(int s, int a, int b, int c){
    if(s == 0){
        if(a == 0 && b == 0 && c == 0)
            return 1;
        // s가 0이고, 나머지가 다 0이면 1을 리턴 해줌
        else
            return 0;
        // s가 0이어도, 나머지 중 하나라도 0이 아니면 0을 리턴
    }
    
    if(a<0 || b<0 || c<0)
        return 0;
    // 하나라도 음수면 0을 리턴
    
    ll& t = dp[s][a][b][c];
    
    if(t != -1)
        return t;
    // dp가 -1이 아닐 경우 즉, 바뀌었을 경우 t로 리턴해줌
    
    // 중복 없애줌
    
    t = 0;
    t += re(s-1, a-1, b, c);        // a만 부르는 경우
    t += re(s-1, a, b-1, c);
    t += re(s-1, a, b, c-1);
    t += re(s-1, a-1, b-1, c);      // a, b가 부르는 경우
    t += re(s-1, a-1, b, c-1);
    t += re(s-1, a, b-1, c-1);
    t += re(s-1, a-1, b-1, c-1);
    // 각각 제귀 호출해준다.
    // return 되는 값에 따라 t에 더해다 줌

    t %= mod;
    
    return t;
    // 위에서 return안하고 재귀적인 함수를 통과하였을 경우 t를 리턴해준다.
    
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int s, a, b, c;
    
    cin >> s >> a >> b >> c;
    
    memset(dp, -1, sizeof(dp));
    // 모든 dp를 -1로 해준다.
    cout << re(s, a, b, c);
    

    
    return 0;
}
