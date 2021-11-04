
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

int arr[1001];
bool check[1001];

void DFS(int n){
    check[n] = true;
    
    int next = arr[n];
    if(!check[next]){
        DFS(next);
    }
    // 이런 식으로 이어진 부분 모두 이어서 check를 true로 바꾸어 준다.
    
}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> t;
    
    while(t--){
        
        cin >> n;
        
        for(int i=1;i<=n;i++){
            cin >> arr[i];
        }
        
        memset(check, 0, sizeof(check));
        
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(!check[i]){
                DFS(i);
                ans++;
            }
        }
        
        cout << ans << '\n';
    }
    
    
    
    
    
    return 0;
}

// 정말 단순한 DFS 문제 인데, 문제 이해를 늦게 해버림..
