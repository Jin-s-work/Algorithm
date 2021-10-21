
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


queue<ll>q;
ll dp[1000001];


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=1;i<=9;i++){
        q.push(i);
        dp[i] = i;              // queue에 i를 넣어주고 dp에도 그 자리에 다 넣어줌
    }
    
    if(n >= 0 && n <= 10){
        cout << n << '\n';      // 1의 자리 수 일 경우 그 순서대로가 맞다.
        return 0;
    }
    
    int now = 10;       // 10부터 시작
    while(now <= n && q.empty() == false){      // 찾는 숫자가 now 이상이고 q가 안비어있을때
        ll num = q.front();
        q.pop();                // num에 queue를 넣어주고
        
        int last = num % 10;            // last에 일의 자리수 넣어준다.
        for(int i=0;i<last;i++){
            q.push(num * 10 + i);
            dp[now++] = num * 10 + i;
        }
    }       // num을 한자리 수 씩 올리고 그 뒤가 작아질 수 있도록 0-last 사이에 push
            // dp에도 now를 하나씩 증가시키면서 순서에 따라서 넣어준다.
            // 이러면 순서대로가 가능하다.
            // now를 증가시키면서 넣어주므로 10부터 해서 쭉 해준다.
    
            // now를 기준으로 하면서 10씩 곱하면서 하면 3, 4자리수도 가능하므로 계속 가능하다.
    
    // dp는 처음에 0으로 모두 되어있으므로 확인 꼭 해줘야 한다.
    if(now >= n && dp[n] != 0)      // dp가 0이 아니고, now가 n보다 크거나 같으면
        cout << dp[n] << '\n';      // 바로 출력해준다.
    else
        cout << "-1" << '\n';       // 0이거나 만족하지 않으면 -1을 출력
                                    // 즉 없을 경우
    
    return 0;
}

// 그냥 그리디하게 모두 해서 보면 계산량이 너무 많을 것이다.

// 1자리 수는 그냥 있어도 감소하는 수이다.
// 두 자리 이상의 숫자는 따로 구해줘야 하는데

// 가장 마지막 숫자 보다 더 작은 숫자들을 추가로 붙이면 된다.

// 즉 1. 가장 마지막 숫자를 구하고  (숫자 % 10) = n
// 2. 0 - (n-1) 까지 숫자를 뒤에 추가하여 붙인다.
// 3. 2단계에서 생성된 숫자를 새로 queue에 넣어준다.
