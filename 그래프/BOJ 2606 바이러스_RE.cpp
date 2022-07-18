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


int arr[101][101] = {0};
int check[101] = {0};
int ans = 0;

void DFS(int now){
    check[now] = true;
    
    for(int i=1;i<=n;i++){
        if(!check[i] && arr[now][i]){
            ans++;
            DFS(i);
        }
        
    }
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;;
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        arr[a][b]++;
        arr[b][a]++;
        
    }
    
    
    DFS(1);
    
    cout << ans;
    
    
    
    return 0;

}


// 서로 연결되어 있는 것을 찾는 것은 DFS가 좋을 것이라 생각
