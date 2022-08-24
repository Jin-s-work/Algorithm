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


int dp[1025][1025];
int arr[1025][1025];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    
    int num;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> num;
            
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + num;
            // 왼쪽위와 위쪽 위를 더해주고 왼쪽 대각선 위는 빼준 뒤에 원래 값을 더해주면서 중복을 피한다.
            // 즉 거꾸로된 ㄴ 모양으로 되는 것이다.
            
            // dp[i-1][j-1] 부분은 항상 중복되므로 이를 빼주는 것이다.
        }
    }
    
    int sum = 0;
    for(int i=1;i<=m;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        sum = dp[c][d] - dp[a-1][d] - dp[c][b-1] + dp[a-1][b-1];
        // 처음의 dp[c][d]는 전체를 뜻한다.
        // 그 다음의 dp[a-1][d]는 시작의 위부분과 대각선 위부분
        // dp[c][b-1]은 시작의 왼쪽부분과 대각선 위부분
        // 여기에서 대각선 위부분을 두번 빼주었으니 한번 더 해주어야 하므로 이렇게 한다.
        // 자세한 그림은 노션에
        
        cout << sum << '\n';
        
    }
    
    
    
    
    
    return 0;
    
}
