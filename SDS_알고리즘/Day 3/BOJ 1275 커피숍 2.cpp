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


vector<ll>v;
vector<ll>tree;
vector<pair<pair<int, int>, pair<int, int>>> vec;

ll make_segtree(int node, int start, int end){
    if(start == end)
        return tree[node] = v[start];
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

ll sum(int node, int start, int end, int left, int right){
    if(left > end || right < start)
        return 0;
    // left가 end를 넘거나 right가 start보다 작을 때는 그냥 0을 리턴
    if(left <= start && end <= right)
        return tree[node];
    // 범위 안에 있을 경우에는 tree[node]를 리턴해준다. 즉 합이다.
        
    int mid = (start + end) / 2;
    ll left_num = sum(node * 2, start, mid, left, right);
    ll right_num = sum(node * 2 + 1, mid + 1, end, left, right);
    // 위와 같이 left, right의 숫자를 sum을 통해 넣는다.
    
    return left_num + right_num;
    
}
// 합을 구해주는 함수


void update_segtree(int node, int start, int end, int idx, ll dif){
    
    if(idx < start || idx > end)
        return;
    // 범위가 지나면 그냥 return
    
    tree[node] = tree[node] + dif;      // 차이를 더해준다.
    
    if(start != end){
        int mid = (start + end) / 2;
        update_segtree(node * 2, start, mid, idx, dif);
        update_segtree(node * 2 + 1, mid + 1, end, idx, dif);
    }
    
}
// segtree를 update


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    for(int i=0;i<m;i++){
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        vec.push_back({{x, y}, {a, b}});
    }
    // a가 1인 경우 b번째 수를 c로 바꾸고,
    // a가 2인 경우 b번째부터 c번째 수 까지 합을 구해 출력한다.
    
    int height = (int)ceil(log2(n));
    int tree_size = (1 << (height + 1));
    // tree의 크기는 2^(height + 1) 만큼
    
    tree.resize(tree_size);
    make_segtree(1, 0, n-1);
    // node는 1부터 시작은 0 마지막은 n-1
    
    for(int i=0;i<m;i++){
        
        
        // a가 2일때   b번째 수부터 c번째 수까지의 합을 구하여 출력
        int idx = vec[i].first.first - 1;      // x번째수는 idx
        int idx2 = vec[i].first.second - 1;    // y번째수는 idx2
        
        if(idx > idx2)
            swap(idx, idx2);
        
        ll res = sum(1, 0, n-1, idx, idx2);     // 합을 구하는 sum
        // b번째수, c번째수
        cout << res << '\n';
        // 이 경우는 값을 더하는 경우
        
        // a를 b로 바꾼다.
        int a_num = vec[i].second.first - 1;      // idx는 a
        int b_num = vec[i].second.second;          // val는 b
        ll dif = b_num - v[a_num];      // c에서 v가 idx위치일때 값을 빼준 값을 diff로
        // diff는 나중에 tree[node]에 더해줌
        
        v[a_num] = b_num;               // v가 idx위치일 때 val을 넣어준다.
        // 즉 둘다 값을 바꾸는 것..
        update_segtree(1, 0, n-1, a_num, dif);        // 즉 바꾸는 update
        // 즉 값을 바꾸는 것이다.
    }
    
    // 순서가 x-y의 합을 구하고, a번째 수를 b로 바꾸는 것이므로
    // 구간 합 구하기 와는 그 순서를 다르게 해주어야 한다.
    

    return 0;

}


// 막상 세그먼트 트리를 한번 익혀놓으면 계속 쓸수는 있겟다는 생각도 들었고,
// 조금 더 익숙해 진 것 같기도...
