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

int parent[201];
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




int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    cin >> m;
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    
    for(int i=1;i<=n;i++){
        int tmp = 1;
        for(int j=1;j<=n;j++){
            cin >> tmp;
            if(tmp == 1)        // 1일 경우에 붙어있으므로, merge한다.
                merge(i, j);
        }                       // 0일 경우를 고려해야 하나 했는데 안해도 되는 듯 하다.
    }
    
    int start, end;
    bool check = true;
    
    cin >> start;
    for(int i=1;i<m;i++){       // m개의 여행계획들이 이제 주어진다.
        cin >> end;
        if(!check)      // true가 아닐 경우  no
            continue;
        
        if(find(start) != find(end))
            check = false;
        
        start = end;
        // start를 end로 바꾸어 다음으로 넘어가 다시 for문을 돌린다.
    }
    
    if(check)
        cout << "YES";
    else
        cout << "NO";
    // 루트가 하나라도 다른 점이 있으면 NO
    
    return 0;

}
