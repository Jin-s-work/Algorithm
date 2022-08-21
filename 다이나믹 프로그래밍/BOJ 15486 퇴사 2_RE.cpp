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
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;

ll dp[1510005];
ll arr[1510005][2];
// if문 없이 그냥 다 더해주므로 크기를 더 크게 해줘야 할 수 밖에 없다

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    
    for(int i=1;i<=n;i++){
        dp[i + arr[i][0]] = max(dp[i + arr[i][0]], dp[i] + arr[i][1]);
        // if문은 뭔가 안써도 정답처리는 되는 거 같다.. 사실 넘어가도 상관은 없으므로
        // if 문때문에 틀린거 같아서 없이 다시 제출해보기..
        
        dp[i + 1] = max(dp[i], dp[i+1]);
        // 사실 이 부분에 대해서 안되서 참조를 해버렸따...
        // 일을 수행하지 않고, 건너뛰는 경우와 일을 수행하는 경우를 비교하여 그 경우가 더 클 경우에는 그대로
        // 따라서 i+1이 될 경우 그 전의 경우가 더 클 경우에는 그 다음의 경우도 1을 크게 해준다.
        
        // 이해 완료
    }
    
    // 다만 문제에서 이해가 안되었던 것은 날짜가 마지막보다 뒤이면 안되는 줄 알앗는데
    // 예시에서도 그렇고 딱 그 다음 까지는 되는듯..? 그렇게 풀어야만 답이 나온다.
    // 77% 정도 내가 풀었다고 할 수 있겟다
    
    
//    for(int i=0;i<=n;i++){
//        cout << dp[i] << '\n';
//    }
    
    cout << dp[n+1];
    
    
    return 0;
    
}
