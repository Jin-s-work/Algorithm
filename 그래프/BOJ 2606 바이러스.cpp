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


int arr[101][101] = {0};
int check[101] = {0};
int ans = 0;

void DFS(int now){
    check[now] = 1;
    for(int i=1;i<=n;i++){
        if(!check[i] && arr[now][i]){
            ans++;
            DFS(i);
            // 해당하는 i에 대해서 다시 들어가서 그 i를 now로 받아서 계속 파고 들어감
        }
    }
    // 간단한 DFS 사용
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    cin >> m;
    
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        arr[a][b]++;
        arr[b][a]++;
    }
    
    DFS(1);
    
    cout << ans;
    
    return 0;

}


// 간단한 DFS를 사용하여 문제를 푼다.
