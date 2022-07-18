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

// control i
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


bool check[100001];
vector<int>v[100001];
vector<int>ans;
int num = 0;
int Max = 0;

void DFS(int now){
    check[now] = true;
    
    for(int i=0;i<v[now].size();i++){
        int next = v[now][i];           // v[now]의 값에 맞게 만큼 해서 next를 구한다.
        if(!check[next]){               // 아직 방문하지 않았을 경우 수를 세며 파고 들어감
            num++;
            DFS(next);
        }
    }
}
// 같은 DFS





int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
        
    }
    
    for(int i=1;i<=n;i++){
        
        memset(check, false, sizeof(check));
        num = 0;
        // 매번 num과 check을 갱신한다.
        
        DFS(i);
        // 각각 1-n 에서 모두 DFS를 실행해서 num을 찾아봄
        
        if(Max == num){         // num이 Max일 경우 그냥 넣어준다.
            ans.push_back(i);
            
        }
        else if(Max < num){     // 더 큰 것이 나왔을 경우
            Max = num;
            ans.clear();
            ans.push_back(i);
            // 더 큰게 있으면 새로 갱신하고 넣어줌
        }
    }
    
    sort(ans.begin(), ans.end());
    
    for(auto k : ans){
        cout << k << " ";
    }
    
    
    
    
    return 0;

}


// 솔직히 조금 더 생각해보면, 충분히 풀 수 있었을 것 같다.
// 경험을 많이 쌓아야겠다.
