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


int tree[100001];
vector<int>arr[100001];

void make_tree(int now){        // tree를 만드는 것인데 사실 그냥 DFS로 재귀적으로 해주는 것
    for(int i=0;i<arr[now].size();i++){     // tree를 만드는 것은 DFS로 하는 게 편할 수 밖에
        int next = arr[now][i];         // 다음 부분을 arr[now][i]로
        
        if(tree[next] == 0){            // 아직 방문되지 않았을 경우
            tree[next] = now;           // 현재의 값을 tree[next]에 넣어주고
            make_tree(next);            // next를 기준으로 다음으로 넘어가며 찾는다.
        }
    }
}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        arr[b].push_back(a);
        // arr[b] = a
        arr[a].push_back(b);
        // arr[a] = b
    }
    
    make_tree(1);
    
    for(int i=2;i<=n;i++){
        cout << tree[i] << '\n';
    }
    
    
    
    
    return 0;

}


// 솔직히 조금 더 생각해보면, 충분히 풀 수 있었을 것 같다.
// 경험을 많이 쌓아야겠다.
