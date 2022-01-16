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

// control i
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


int arr[1025][1025];
int dp[1025][1025];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> k;
            
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + k;
            // 왼쪽 아래 + 오른쪽 위를 더하고 왼쪽 위는 빼준 뒤에 원래 값을 더해준다.
            // (중복 피하는 것)
        }
    }
    
    int sum = 0;
    for(int i=1;i<=m;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        sum = dp[c][d] - dp[a-1][d] - dp[c][b-1] + dp[a-1][b-1];
        
        cout << sum << '\n';
    }
    
    

    return 0;

}

