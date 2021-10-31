
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


vector<int>v[2001];
bool check[2001];
bool flag;

void DFS(int now, int num){
    if(num == 4){           // 만약 num이 4가 되면 true로 하고 DFS를 끝낸다.
        flag = true;
        return;
    }
    
    // 밑에서 v[now].size로 하는 것은 v[now]에서 가는 길들이 여러개 일 경우
    // 그 길에 대해서 now에서 가는 길의 i번째 항목을 의미하는 것이다.
    // 즉 now에서 갈 수 있는 길의 목록중 i번째 이다.
    // 예를 들어서 1->2, 1->3, 1->4일 경우, v[1] = 2, 3, 4이기 때문이다..?
    // 그래서 i를 0부터 v[now].size로 모든 경우를 탐색해줌
    
    check[now] = true;          // 현재인 now를 지났다고 표시해 주고
    for(int i=0;i<v[now].size();i++){
        int next = v[now][i];       // now에서 다음으로 가는 i의 값을 일단 next를 넣어주고
        // 모두 한방향으로 가는 v가 4개 존재하면 되므로 false일 경우 계속 이어준다.
        if(check[next] == false)    // 만약 next가 지나지 않았다면
            DFS(next, num + 1);     // next에 관해 num을 하나 더 늘려서 해본다.
        if(flag)        // 만약 flag가 true면 그냥 return한다.
            return;
    }
    // 즉 여기서 지금인 now에 관하여 now에서 다음으로 가는 v[now][i]에 관해
    // 만약 next가 아직 지나지 않은 상태일 경우, next에 관해서 num을 하나 증가시켜서 해보아준다.
    // 즉 뜻으로는 아직 탐색되지 않은 친구관계일 경우 찾아가면서 진행하는 것
    
    check[now] = false;     // now에 대해 진행을 그냥 해주고 여기로 왔으면 다시 false로 해준다.
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i=0;i<n;i++){
        memset(check, false, sizeof(check));
        // 할때마다 check를 false로 초기화해서 사용해줌
        DFS(i, 0);
        // now를 각각 i로 0-n 까지 중 찾아본다.
        if(flag)
            break;
        // flag가 이미 있으면 끝낸다.
    }
    
    if(flag)
        cout << "1" << '\n';
    else
        cout << "0" << '\n';
    // 못 찾은 친구의 경우 그냥 0을 출력한다.
    
    
    
    return 0;
}

