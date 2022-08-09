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
const int INF = 1000000000;
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
ll n,m,k;
ll l,r,t;
int h;
      

map<ll, ll>mp;
ll a[1001];
ll b[1001];
ll ans = 0;



int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
   
    cin >> t;
    
    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> m;
    for(ll i=0;i<m;i++){
        cin >> b[i];
    }
    
    for(ll i=0;i<n;i++){
        ll tmp = 0;
        for(ll j=i;j<n;j++){
            tmp += a[j];
            if(abs(tmp) <= INF)
                mp[tmp]++;
        }
    }
    // 즉 여기서 a에 대하여 a에 대한 모든 배열들의 합을 mp에 저장해놓는 것이다.
    
    
    // 다른 문제에서 푼 투 포인터 문제와 비슷하게
    // 밑에 배열에서는 tmp를 t로 잡아서 b[j]를 뺀다. 만약 빼서 INF를 아직 넘을 경우에는 넘어가고
    // 아닌 경우에는 mp[tmp]의 경우의 수로 넣어준다. ( 가능하므로 )
    
    // 즉, t-b의 모든 부배열 합이 = sum일 경우에 ans로
    for(ll i=0;i<m;i++){
        ll tmp = t;
        for(ll j=i;j<m;j++){
            tmp -= b[j];
            if(abs(tmp) > INF)
                break;
            // 범위를 넘는 경우에만 빠져나가고
            // 아닐 경우 tmp라는 합에 대한 경우의 수를 ans에 더해준다.
            
            ans += mp[tmp];
        }
    }
    


    cout << ans;
    
    // 전 문제에서 썼던 나누어서 투 포인터는 시간 초과가 떠서 안된다
    // t가 1000000000 이라서
    
    
    return 0;
    
}

// 1
// 1 3 2

// 1 2
// 1 3

// 1 3
// 1 2

// 1 1
// 3 2

// 1 3 1
// 2

// 1 3 2
// 1

// 1312
// -
