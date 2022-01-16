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

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>

using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;

int arr[1000001];
vector<ll>v;
vector<ll>tree;
vector<pair<pair<int, int>, pair<int, int>>> vec;

ll make_segtree(int node, int start, int end){
    
    if(start == end)
        return tree[node] = arr[start];
    // start와 end가 같으면 v[start]를 tree[node]에 넣는다.
    
    int mid = (start + end) / 2;
    ll left_num = make_segtree(node * 2, start, mid);
    ll right_num = make_segtree(node * 2 + 1, mid + 1, end);
    // left와 right의 숫자는 node를 *2 *2-1로 해주고 범위도 나눔
    
    tree[node] = left_num + right_num;
    // tree의 노드는 left와 right를 더해서 해줌
    
    return tree[node];
}
// 처음 세그먼트 트리를 만드는 함수
// ((( 구간 합 구하기 1과 같다. )))

void Lazy(int node, int start, int end){
    
    if(v[node] != 0){
        tree[node] = tree[node] + (end - start + 1) * v[node];
        // tree의 node에 (길이 + 1) * v[node]를 해준다.
        
        if(start != end){       // start와 end가 다를 때
            v[node * 2] = v[node * 2] + v[node];
            v[node * 2 + 1] = v[node * 2 + 1] + v[node];
        }
        // v[node * 2] 에 v[node]를 더해준다.
        // v[node * 2 + 1]에 v[node]를 더해준다.
        
        v[node] = 0;
        // 0이 아니라서 진행하여 주고, v[node]는 0으로 해준다.
        // 즉 node*2와 node*2+1에 값을 갱신해주고, v[node]는 썼으므로 0으로 해줌
    }
}

ll query(int node, int start, int end, int left, int right){
    
    Lazy(node, start, end);
    
    if(left > end || right < start)
        return 0;
    // left가 end를 넘거나 right가 start보다 작을 때는 그냥 0을 리턴
    if(left <= start && end <= right)
        return tree[node];
    // 범위 안에 있을 경우에는 tree[node]를 리턴해준다. 즉 합이다.
        
    int mid = (start + end) / 2;
    ll left_num = query(node * 2, start, mid, left, right);
    ll right_num = query(node * 2 + 1, mid + 1, end, left, right);
    // 위와 같이 left, right의 숫자를 sum을 통해 넣는다.
    
    return left_num + right_num;
    
}
// 합을 구해주는 함수


void update_segtree(int node, int start, int end, int left, int right, ll val){
    
    Lazy(node, start, end);
    // Lazy를 일단 한번 해주고
    
    if(right < start || left > end)
        return;
    // 범위가 지나면 그냥 return
    
    if(left <= start && end <= right){      // 범위 안의 구간에서
        tree[node] = tree[node] + (end - start + 1) * val;
        
        if(start != end){
            v[node * 2] = v[node * 2] + val;
            v[node * 2 + 1]  = v[node * 2 + 1] + val;
        }
        return;
    }
    // Lazy와 같이 해줌
        
    int mid = (start + end) / 2;
    update_segtree(node * 2, start, mid, left, right, val);
    update_segtree(node * 2 + 1, mid + 1, end, left, right, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    // tree에는 node를 위로 옮겨가준다.
    // 이래서 bottom-up인듯
    
}
// segtree를 update


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m >> k;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    for(int i=0;i<m+k;i++){
        int a, b;
        int c, d;
        
        cin >> a;
        if(a == 1){
            cin >> b >> c >> d;
            vec.push_back({{a, b}, {c, d}});
        }
        else{
            cin >> b >> c;
            vec.push_back({{a, b}, {c, -1}});
        }
    }
    // a가 1인 경우 b부터 c에 d를 더한다.
    // a가 2인 경우 b번째부터 c번째 수 까지 합을 구해 출력한다.
    
    int height = (int)ceil(log2(n));
    int tree_size = (1 << (height + 1));
    // tree의 크기는 2^(height + 1) 만큼
    
    tree.resize(tree_size);
    v.resize(tree_size);
    // tree와 v를 총 개수 만큼 할당해준다.

    make_segtree(1, 0, n-1);
    // node는 1부터 시작은 0 마지막은 n-1
    
    for(int i=0;i<m+k;i++){
        int tmp = vec[i].first.first;
        
        if(tmp == 1){       // a가 1일때  b를 c로 바꾼다.
            int idx = vec[i].first.second - 1;      // idx는 b
            int idx2 = vec[i].second.first - 1;     // idx2는 c
            ll val = vec[i].second.second;          // val은 d를 의미
            
            update_segtree(1, 0, n-1, idx, idx2, val);        // 즉 바꾸는 update
        }           // 즉 값을 바꾸는 것이다.
        else{               // a가 2일때   b번째 수부터 c번째 수까지의 합을 구하여 출력
            int idx = vec[i].first.second - 1;      // b번째수는 idx
            int idx2 = vec[i].second.first - 1;    // c번째수는 idx2
            
            ll res = query(1, 0, n-1, idx, idx2);     // 합을 구하는 sum
                                    // b번째수, c번째수
            cout << res << '\n';
        }               // 이 경우는 값을 더하는 경우
    }
    
    

    return 0;

}



// 세그멘트 트리 이해는 이제 가지만 그래도 쉽지가 않다...
// 혼자 할수 있으려나

// 그 다음 문제라 풀어봤는데 역시 혼자 할 수가 없었다....
// Lazy propagation에 대해서 더 알아야 할듯 풀라믄... 근데 일반 코테에서는 절대 안쓸듯... 패스
