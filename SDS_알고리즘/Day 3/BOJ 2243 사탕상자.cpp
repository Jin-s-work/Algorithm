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

int gcd(int a, int b){
    
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

#define MAXI 1000000
int arr[MAXI + 4];
vector<ll>tree;
vector<pair<int, pair<int, int>>> vec;

int query(int node, int start, int end, int num){
    if(start == end)
        return start;
    // 시작과 끝이 같으면 시작을 return
    
    int mid = (start + end) / 2;
    if(tree[node * 2] >= num)
        return query(node * 2, start, mid, num);
    // 만약 왼쪽의 값이 num 이상일 경우
    // query에서 node*2를 하고 왼쪽부분으로 들어가서 리턴한다.
    
    return query(node * 2 + 1, mid + 1, end, num - tree[node * 2]);
    // 아닌 경우 node*2+1로 들어가서 오른쪽부분으로 들어가서 리턴하고, num은 tree[node*2]를 빼준다.
    
}

void update(int node, int start, int end, int idx, int diff){
    if(idx < start || idx > end)
        return;
    // 범위가 idx가 start와 end 범위 안에 없으면 리턴
    
    tree[node] = tree[node] + diff;
    // 차이를 더해다 줌
    
    if(start != end){
        int mid = (start + end) / 2;
        
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
        // 같지 않을 경우 각각 들어가서 update해 준다. 즉 diff를 더해줌
    }
    
}




int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        
        if(a == 1){
            int b;
            cin >> b;
            
            vec.push_back({a, {b, -1}});
        }
        else{
            int b, c;
            cin >> b >> c;
            
            vec.push_back({a, {b, c}});
        }
        
    }
    
    int height = (int)ceil(log2(MAXI));
    int tree_size = (1 << (height + 1));
    
    tree.resize(tree_size);
    // tree를 저만큼 사이즈로 할당해준다.
    
    for(int i=0;i<vec.size();i++){
        int tmp = vec[i].first;
        
        if(tmp == 1){
            int idx = vec[i].second.first;
            int now = query(1, 1, MAXI, idx);
            // tmp가 1일 경우 b는 idx로
            // now는 node가 1, 시작이 1, 끝이 백만, num은 idx
            
            cout << now << '\n';
            arr[now]--;
            update(1, 1, MAXI, now, -1);
            // now를 출력하고, arr에서 하나 줄여준 뒤에
            // node가 1, 시작이 1, 마지막이 백만, 인덱스는 now이고, diff를 -1로 해서 줄인다.
            // 그래서 update인 것
            
        }
        else{
            int idx = vec[i].second.first;
            int val = vec[i].second.second;
            // 1이 아닐 경우 사탕을 넣는 경우이다.
            // b는 idx, c는 val
            
            arr[idx] = arr[idx] + val;
            update(1, 1, MAXI, idx, val);
            // arr의 b 인덱스에는 val을 즉 c를 더해주고 그를 업데이트 해주는 것
            
        }
        
        
    }
    
    
    
    
    
    
    

    return 0;

}












//
//
//
//
//cin >> n >> k;
//
//priority_queue<int>pq;
//vector<int>v;
//
//for(int i=0;i<n;i++){
//    int a;
//    cin >> a;
//    v.push_back(a);
//}

