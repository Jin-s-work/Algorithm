
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


string st;
int dp[1001];

char check(int i){
    if(st[i] == 'B')
        return 'O';
    if(st[i] == 'O')
        return 'J';
    if(st[i] == 'J')
        return 'B';
    
    return 'A';
}
// 지금 알파벳을 찾고, 그 다음에 나와야 할 단어를 return 해줌

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    cin >> st;
    
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    // dp를 모두 -1로 해놓고, 처음은 0으로 시작함
    
    // 못할 경우 -1을 리턴해야 되기 때문에 전체를 -1로 놓고
    // 못 지나가면 그냥 -1을 리턴하여 불가능함을 알려줌
    
    for(int i=0;i<n;i++){
        
        if(dp[i] == -1)
            continue;
        // 그냥 -1이면 넘어감
        
        char next = check(i);
        // 배열의 위치에 따라 다음에 와야할 단어를 넣어줌
        
        for(int j=i+1;j<n;j++){
            if(next != st[j])
                continue;
            // i+1 즉 단어의 다음부터 탐색하면서 다를 경우 넘어가고
            // 아닐 경우 진행한다.
            // 즉, 뒤에가 실행되기 위해서는 다음 단어를 만족할 경우
            
            // 만족할 경우 (다음으로 점프할 경우)
            if(dp[j] == -1)
                dp[j] = dp[i] + (j-i)*(j-i);
            // dp가 아직 안변한 -1일 경우 dp[j]에다가 원래의 dp[i]에서의 차이의 제곱을 더해줌
            
            dp[j] = min(dp[i] + (j-i) * (j-i), dp[j]);
            // 그러고 나서 원래의 dp[j]와 다른 경우를 비교해준다.
            // 즉 이미 j가 전에 비교가 되었을 경우 새로 한 것과 비교해 주는 것
        }
    }
    
    cout << dp[n-1];

    
    return 0;
}


// 한번에 k칸 점프를 할때, 필요한 에너지의 양이 k*k이므로, 최대한 짧게 짧게 많이 움직이는 것이 이득이다.

// B면 다음 O를 찾고, 그 다음은 J를 찾는다. 이를 계속 반복
// 맨 마지막이 중요하므로, 뒤에서 부터 거꾸로 찾는것도 괜찮아 보이기도 하고..

// 다 해놓고 보니, 제일 가까운 다음 알파벳을 찾는 것이다.
