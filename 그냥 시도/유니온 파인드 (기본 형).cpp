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
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


int parent[1000001];

int find(int x){
    if(parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    
    if(a != b){
        parent[a] = b;
    }
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;
    
    for(int i=0;i<=n;i++){
        parent[i] = i;
    }
    
    for(int i=0;i<m;i++){
        
        int a, b, c;
        cin >> a >> b >> c;
        
        if(a == 0){
            merge(b, c);
        }
        else if(a == 1){
            if(find(b) == find(c))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
        
        
    }



    return 0;

}

// 유니온 파인드

// 합치는 유니온과 찾는 파인드를 섞음
