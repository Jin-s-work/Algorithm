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


vector<int>v[2001];
bool check[2001];
bool flag;

void DFS(int now, int num){
    if(num == 4){
        flag = true;
        return;
    }   // num이 4가 될 경우에 true로 하고 DFS를 끝낸다.
        // 4번 연속으로 연결되는 것이 한개라도 있을 경우 가능 한 것이다.
    
    check[now] = true;
    for(int i=0;i<v[now].size();i++){
        int next = v[now][i];
        if(check[next] == false)
            DFS(next, num + 1);     // next가 false일 경우 DFS
        if(flag)
            return;     // flag가 true면 return
    }
    
    check[now] = false;
    // 방문처리를 안할 경우 시간 복잡도가 너무 늘어난다.
    // 그래서 리턴할 떄 다시 삭제해준다.
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        
        int a, b;
        cin >> a >> b;
        
        v[b].push_back(a);
        v[a].push_back(b);

    }
    
    for(int i=0;i<n;i++){
        memset(check, false, sizeof(check));
        
        DFS(i, 0);
        
        if(flag)
            break;
    }
    
    if(flag)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
    // 4번 연속으로 연결되는 DFS를 할때 깊이가 4인 것이 단 한개라도 잇으면 1을 출력한다.
    
    return 0;

}
