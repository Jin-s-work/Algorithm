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
#define mod 1000000000
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


int dp[4001][4001];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    string a, b;
    cin >> a;
    cin >> b;
    
    int ans = 0;
    for(int i=0;i<a.length();i++){
        for(int j=0;j<b.length();j++){
            if(a[i] == b[j]){           // 같은 경우에 대해서
                if(i == 0 || j == 0)    // 둘 중 하나가 처음 나왔을 경우
                    dp[i][j] = 1;       // 1로 초기화해준다.
                else
                    dp[i][j] = dp[i-1][j-1] + 1;
                // 아닌 경우 그 전에서 1을 더해준다.
                
                ans = max(ans, dp[i][j]);
                // 값들 중에 max를 찾는다.
            }
                
        }
    }
    
    cout << ans;
    
    return 0;
    
}
