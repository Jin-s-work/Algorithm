
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
//int n,k;
int l,r,t;
int h, w;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    
    while(t--){
        
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        int n;
        cin >> n;
        
        for(int i=0;i<n;i++){
            ll a;
            cin >> a;
            pq.push(a);
        }
        // 우선순위 큐에 입력 받은 것을 넣어준다.
        
        ll ans = 0;
        for(int i=0;i<n-1;i++){     // 합치기 횟수 자체는 n-1번이므로
            ll tmp = 0;
            tmp = pq.top();
            pq.pop();
            
            tmp += pq.top();
            pq.pop();
            
            // 두번 더해주고, 두번 뺀다.
            
            pq.push(tmp);
            // 그러고 나온 값을 다시 큐에 넣어준다.
            // 이 값이 새로 들어가서 다른 것들과 연산됨
            ans += tmp;
            // 이 과정에서 ans에 더해준다.
            // 한 번 하였기 때문에
        }
        
        
        cout << ans << '\n';
        // 연속적으로 답을 구하는 것인데, 줄 바꿈 안해서 틀렸었던 듯..
        
    }
    
    
    return 0;
}


// 최소 힙을 구현하여 간단하게 할 수 있다.
// 이진트리 기반으로 모든 부모 노드가 자식들의 노드보다 작은 구조를 말한다.

// 복잡하게 더하고 넣고, 정렬하고 하는 것보다 훨씬 빠르다.
// 최소 힙을 만들어, 모든 파일을 넣고, 최소 힙의 루트 노드를 두번 더하고 빼고, 다시 넣는 것을 반복한다.
// 이 과정에서 n개의 파일을 1개로 줄이는 합치기 횟수 자체는 n-1번 이므로, 과정을 n-1번 반복한 결과를 출력해준다.

// 우선 순위 큐와 힙에 대해 더 공부해야 할듯..
