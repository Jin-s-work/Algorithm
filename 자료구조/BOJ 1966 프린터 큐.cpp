
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


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    
    while(t--){
        
        queue<pair<int, int>> q;
        priority_queue<int>pq;
        // 큐를 sort 하기 위해서 우선순위 큐를 사용
        
        cin >> n >> m;
        int ans = 0;
        
        // 처음에는 1-n으로 했는데 맨 왼쪽은 0번째라고 하니
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            q.push({a, i});
            pq.push(a);
            // pq는 a가 순서대로 정렬되어 있다.
        }
        
        while(!q.empty()){
            int now = q.front().first;
            int num = q.front().second;
            q.pop();            // now는 중요도고 num은 인덱스이다.
            
            // top이 보통의 우선순위 큐에서 제일 큰 수이기에 여기부터 찾아서 출력한다.
            if(pq.top() == now){        // pq의 제일 중요한 것이 현재이면 우선순위 큐를 pop하고
                pq.pop();               // ans를 늘려준다.
                ans++;              // 즉 제일 위에있는 pq와 중요도가 같아질 때
                
                if(num == m){           // 더해진 ans가 m이 되면 ans를 출력하고 끝냄
                    cout << ans << '\n';
                    break;
                }
            }
            else
                q.push({now, num});
            // 아닐 경우 다시 now와 num을 넣어준다.
        }
        
    }
    
    // 우선순위 큐는 다른 cmp같은 비교함수가 없는 한, 내림차순에 따라서 정렬한다.
    // 따라서 맨 앞에 있는 top이 제일 큰 수가 되는 것
    
    return 0;

}


// 큐 문제를 풀때마다 우선순위 큐에 관한 공부가 필요해 보인다.
