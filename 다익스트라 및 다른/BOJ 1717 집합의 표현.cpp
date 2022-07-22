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


int  parent[1000001];

int find(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b)
        return;
    
    parent[b] = a;
}

bool isunion(int a, int b){
    a = find(a);
    b = find(b);
    
    if(a == b)
        return true;
    else
        return false;
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    
    for(int i=0;i<m;i++){
        int k, a, b;
        cin >> k >> a >> b;
        
        if(k == 0){
            merge(a, b);
        }
        else if(k == 1){
            if(isunion(a, b))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
        
    }
    
    // 가장 기본적인 유니온 파인드 문제
    // 유형이 아주 심플하므로 find, merge, isunion 함수만 기억하면 되고
    // 초기화해주는 것을 잊으면 안된다.
    
    
    return 0;

}
