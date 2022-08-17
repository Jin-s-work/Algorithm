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


int dp[31][31];

int Com(int m, int n){
    if(dp[m][n] > 0)
        return dp[m][n];
    if(m == n || n == 0)
        return 1;
    else{
        dp[m][n] = Com(m-1, n-1) + Com(m-1, n);
        
        return dp[m][n];
    }
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> t;
    while(t--){
        cin >> n >> m;
        
        
        
        cout << Com(m,n) << '\n';
        
    }
    
    // 이 문제 자체는 mCn 임을 사용하는 것이고
    // mCn = m-1Cn-1 + m-1Cn 의 성질을 사용한다.
    
    
    
    
    return 0;
    
}
