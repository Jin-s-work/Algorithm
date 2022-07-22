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


int dp[31][31];


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
    
        memset(dp, 0, sizeof(dp));

        int n, m;
        cin >> n >> m;
        
        for(int j=1;j<=m;j++){
            dp[1][j] = j;
        }       // 1개일 경우에는 그냥 무조건 뒤에 다리 개수만큼
        
        for(int i=2;i<=n;i++){
            for(int j=i;j<=m;j++){      // j에서 k도
                for(int k=j;k>=i;k--){  // k는 j에서 i로 줄어든다.
                    dp[i][j] = dp[i][j] + dp[i-1][k-1];
                }
            }
        }
        
        cout << dp[n][m] << '\n';
        
    }
    
    // dp[a][b] = dp[a-1][1] + dp[a-1][2] + ... + dp[a-1][b-1]
    
    return 0;

}
