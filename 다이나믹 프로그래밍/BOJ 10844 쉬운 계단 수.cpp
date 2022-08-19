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

#define MOD 1000000000
int dp[1001][11];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // 처음에 나오는 것은 1-9
    // 그 다음은 0-9가 가능인데, 앞이 9였으면 0-8
    // 그 다음은 0-9가 가능인데, 앞이 9면 0-8, 앞이 0이면 1-9
    
    int sum = 0;
    cin >> n;
    
    for(int i=0;i<10;i++)
        dp[1][i] = 1;
    // 1의 자리수의 경우에는 모두 가능하므로 1개씩을 넣어준다.
    
    // i가 1인 경우는 위에서 고려해 주었기 때문에 2부터 한다.
    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++){
            if(j == 0)      // 0일 경우에는 전에가 무조건 1이므로 이렇게 잇기
                dp[i][0] = dp[i-1][1] % MOD;
            else if(j == 9) // 9일 경우에는 전에가 무조건 8일때만 이므로 이렇게 잇기
                dp[i][9] = dp[i-1][8] % MOD;
            else
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
            // i자리 수에 대해서 j가 되려면 j-1과 j+1에서 오는 수 밖에 없으므로 둘을 더해준다.
        }
    }
    
    // n이 1일때에도 0-9로 하지 않고, 1-9로 하는 것은 0으로 시작할 수가 없기 때문이다.
    // 즉 뒷자리에서 앞자리로 찾는 순서라고 생각하면 i에 대해서 0이 절대 나올 수 없다고 생각하면 된다.
    // (여기서의 i는 제일 앞의 수)
    for(int i=1;i<=9;i++){
        sum += dp[n][i];
        sum %= MOD;
    }
    // n자리 일때의 1-9까지의 합을 모두 sum에 더해준다.
    // 더할 때마다 MOD로 나누어서 나머지로 해줌
    
    cout << sum % MOD;
    
    
    return 0;
    
}
