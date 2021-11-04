
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
int h, w;

char c[51][51];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int ans = 1;
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> c[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<min(n, m);k++){
                // k는 n과 m중에 작은 거 까지로 해야 하는 것이 정사각형을 만들때, 최소를 넘으면 안됨
                if(i + k < n && j + k < m && c[i][j] == c[i][j + k] && c[i][j] == c[i + k][j + k] && c[i][j] == c[i + k][j])
                    ans = max(ans, k + 1);
                // 각각 인덱스가 사각형 범위들을 넘지 않고, 각 변들이 같을 경우 이동한 k와 원래 ans중
                // 큰 것을 넣어준다. k는 0부터 이므로 1더해준다.
            }
        }
    }
    
    cout << ans*ans;
    
    
    
    
    
    return 0;
}
