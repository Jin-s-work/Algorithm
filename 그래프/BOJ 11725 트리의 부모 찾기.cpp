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


int tree[100001];
vector<int>arr[100001];

void tree_make(int now){
    for(int i=0;i<arr[now].size();i++){    // 처음에 들어오는 now에서 뻗어나가는 횟수만큼
        int next = arr[now][i];
        // 벡터에 v[a].push_back(b)와 같이 넣었으므로, arr[a]의 값은 무조건 b이다.
        // 그러므로 이와 같이 나아가며 넣어주고, tree[next]의 값은 now로 각각 그 부모 값을 저장해준다.
        if(tree[next] == 0){        // 만약에 now에서 가는 i가 0일 경우( 즉 방문 안했을떄)
            tree[next] = now;       // tree의 부모는 지금 나아가기 전의 노드이다.
            tree_make(next);     // 계속 들어가는 DFS 방식
        }
    }
}
// DFS를 진행하면서 나아가는 방향의 노드가 아직 방문하지 않은 상태 일때,
// 그 노드를 탐색하고, 동시에 방금 있었던 노드를 새로 간 노드의 부모로 설정한다.



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    tree_make(1);
    
    for(int i=2;i<=n;i++){
        cout << tree[i] << '\n';
    }
    
    
    
    return 0;

}


// 트리를 파고드므로 DFS로 풀면 될 거 같다.
// 개수가 커서 배열은 안되고 벡터로 해야할듯..?

// DFS를 사용하여 하는 것은 같고, 방문 하지 않았을 경우 이동해주면서 그 전의 노드를 새로운 배열에 저장해주며
// 나아간다.
