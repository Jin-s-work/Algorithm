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


int dp[1001][1001];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    string st1, st2;
    cin >> st1;
    cin >> st2;
    
    for(int i=1;i<=st1.length();i++){
        for(int j=1;j<=st2.length();j++){
            if(st1[i-1] == st2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                
        }
        
        
    }
    
    cout << dp[st1.length()][st2.length()];
    
    // 하다 말음
    
    return 0;
    
}

// 문자가 같으면 현재 위치의 값 = 왼쪽 대각선 값 + 1 (배열 범위를 벗어나면 0)
// 문자가 다르면 현재 위치의 값 = max(왼쪽, 위쪽 값)

//0 A C A Y K P
//0 0 0 0 0 0 0
//C 0 1 1 1 1 1
//A 1 1 2 2 2 2
//P 1 1 2 2 2 3
//C 1 2 2 2 2 3
//A 1 2 3 3 3 3
//K 1 2 3 3 4 4


// 같은 문자가 나오면 이전까지의 LCS의 길이에 +1을 한다. 이전까지의 LCS의 길이란 왼쪽 값이 아닌 대각선
// 즉, 왼쪽 위의 값을 말한다. 이는 두 문자열에서 해당 두 문자를 비교하기 전인 LCS의 길이에 +1을 하기 위해서다

// 비교한 문자가 다르다면, 포함되어있는 직전 LCS 즉, 위와 왼쪽 값 중 큰 값이 오게 된다.
