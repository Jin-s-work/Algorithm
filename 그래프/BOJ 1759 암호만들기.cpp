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


char c[21];
void DFS(int now, int a, int b, string str){
    if(str.size() == n){
        if(a < 2 || b < 1)
            return;
        // 사이즈가 맞고 아직 a가 2개 미만이고, b가 1개 미만 일 경우 리턴
        
        cout << str << '\n';
    }
    
    for(int i=now;i<m;i++){     // now부터 m-1까지 탐색하며 모든 경우를 탐색한다.
        if(c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u')
            DFS(i + 1, a, b + 1, str + c[i]);
        // 모음이 하나라도 있을 경우 now도 하나 늘려주고, b의 개수도 늘려주고, str에 c[i]를 더해준다.
        else
            DFS(i + 1, a + 1, b, str + c[i]);
        // 아닌 경우에는 자음이 있는 것이므로 a를 늘려준다.
        
    }
}



int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> c[i];
    }
    
    sort(c, c + m);
    // 오름차순이기에 sort를 먼저 하고 BFS를 진행해준다.
    
    DFS(0,0,0,"");
    
    
    return 0;
    
}

