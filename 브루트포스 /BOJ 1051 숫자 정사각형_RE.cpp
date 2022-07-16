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




int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string st[101];
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> st[i];
    }
    
    int ans = 0;
    int num = min(n, m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<num;k++){
                if(i + k < n && j + k < m && st[i][j] == st[i+k][j] && st[i][j] == st[i][j+k] && st[i][j] == st[i+k][j+k]){
                    ans = max(ans, k + 1);
                }
                    
            }
        }
    }
    // 8개월전에 내가 생각한 데로 풀었다 다만 범위에 대해서 고민이엇는데 그냥 if 문에 i+k < n 과 j + k < m
    // 을 추가하는 것
    
    cout << ans * ans;
    
    
    return 0;

}
