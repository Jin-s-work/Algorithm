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

// control i처
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


vector<pair<int, int>> v[10001];
bool check[10001] = {0};
int ans = 0;
int last = 0;

void DFS(int now, int len){
    if(check[now])
        return;
    // true일 경우 그냥 return 한다.
    check[now] = true;
    // 아직 안지났을 경우 true로 해주고
    
    if(ans < len){
        ans = len;
        last = now;
    }
    // 길이가 원래 보다 길면 갱신해주고, last에 결국 제일 먼 거리를 가진 위치를 넣어준다.
    
    for(int i=0;i<v[now].size();i++){
        DFS(v[now][i].first, len + v[now][i].second);
    }
    // 여기서 DFS로 파고드는데, v[now]에서 다음으로 가게 넣는다.
    // now에서 갈 수 있는 다음 노드, 길이 + now에서 갈 수 있는 거리 (거리를 계속 누적해서 더해준다.
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    for(int i=0;i<n-1;i++){
        int a, b, c;
        cin >> a >> b >> c;
        
        v[a].push_back({b, c});
        v[b].push_back({a, c});
        // vector<pair<int, int>> v[] 로 a, b, c 그리고 b, a, c를 넣어줄 수 있다.
    }
    
    DFS(1,0);
    // 처음 시작을 1로 하여서 가장 멀리있는 지점을 찾는다.
    // 여기서 거리가 최대인 last를 찾는 것이다.
    
    ans = 0;
    memset(check, false, sizeof(check));
    // check를 다시 초기화해주고
    
    DFS(last, 0);
    // 가장 멀리있는 지점과의 거리를 구하기 위해 DFS를 한다.
    
    cout << ans;
    
    return 0;

}


