
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

vector<int>v[10001];
bool check[10001];
int cnt = 0;
int tmp;

void DFS(int num){
    check[num] = true;
    // 먼저 일단 방문한 num을 true로 체크
    for(int i=0;i<v[num].size();i++){
        int next = v[num][i];
        // num에서 i로 가는 벡터를 next로 놓고
        
        if(!check[next]){       // 만약 next가 방문되지 않았을경우
            cnt++;              // 횟수를 늘려주고
            DFS(next);          // next에 관해서 DFS를 재귀적으로 해준다.
        }
    }
}
// v[b][a] 이런 식으로 되므로, next에 v[현재][다음] 이런 식으로 해서 해준다.

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }   // 방향이 b -> a
    
    vector<int>ans;
    
    for(int i=1;i<=n;i++){
        memset(check, false, sizeof(check));
        cnt = 0;        // DFS를 해주기 위해서 check를 계속 새로 바꾸어 놓는다.
        
        DFS(i);
        // 1부터 n까지 DFS를 진행해준다.
        
        if(tmp == cnt)
            ans.push_back(i);   // tmp와 cnt가 같을 경우 i를 벡터에 넣어줌
        else if(tmp < cnt){
            tmp = cnt;          // cnt가 더 클 경우 tmp에 넣어주고
            ans.clear();        // ans를 다시 초기화 시켜주고
            ans.push_back(i);   // 새로 넣는다.
        }                       // 즉, 새로운 최대가 발견되면, 그와 맞는 새로운 값을 넣어줘야 하기에
    }
    
    // 다 했을 경우 정렬하고 출력해준다.
    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
    
    cout << '\n';
    
    return 0;
}
