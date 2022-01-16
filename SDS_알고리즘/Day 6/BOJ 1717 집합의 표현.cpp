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
    
    return parent[x] = find(parent[x]);
    // 경로 압축
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x != y)
        parent[x] = y;
    // 둘이 다를 경우 merge시켜줌
}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    for(int i=0;i<=n;i++){
        parent[i] = i;
    }
    // 처음에 본인의 수를 노드에 넣어줌
    
    for(int i=0;i<m;i++){
        
        int a, b, c;
        cin >> a >> b >> c;
        
        if(a == 0){
            merge(b, c);
        }
        // a에 1이 들어오면 b,c를 합친다.
        
        else if(a == 1){
            if(find(b) == find(c))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
        
        
    }
    
    
    
    

    return 0;

}


// 유니온 파인드 제대로 배워서 처음 해보는 데 간단하고 괜찮은 듯
