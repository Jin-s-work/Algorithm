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
#include <set>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h, w;


vector<int>v[100001];
bool check[100001];
int num = 0;
int cnt;

void DFS(int now){
    check[now] = true;
    
    for(int i=0;i<v[now].size();i++){
        int next = v[now][i];
        if(check[next] == 0){
            num++;
            DFS(next);
        }
    // 평소의 DFS와 같다.
        // next를 잡아서 false일 경우 num을 증가시키고, 그 next로 이동하여 파고들어감
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
    
    vector<int>ans;
    
    for(int i=1;i<=n;i++){
        memset(check, false, sizeof(check));
        num = 0;
        // 매번 check를 새로 하고, num도 계속 갱신
        
        DFS(i);
        // 모든 i에 대하여 돌려준다.
        
        // 그 시작하는 i에 따라서 num이 나오면,
        
        if(cnt == num){
            ans.push_back(i);
            // cnt와 같게 되면 답 벡터에 넣어준다.
            
            // 즉 같은 최대값이 나왔을 때 다음 값도 넣어주는 것이다.
        }
        else if(cnt < num){
            cnt = num;
            ans.clear();
            ans.push_back(i);
            // num이 더 커질 경우 cnt에 num을 저장하고, ans를 없애고 다시 넣어준다.
            // 즉 num이 점점 커질 수록 새로 넣어주고, 그 i를 넣어준다.
        }
        // 더 큰 num이 나오지 않을 경우 그냥 넘어감
        // 다음으로 넘어감
        
        
        
    }
    
    sort(ans.begin(), ans.end());
    // 정렬을 해준다.
    
    for(auto k : ans){
        cout << k << " ";
    }
    cout << '\n';
    
    
    
    return 0;

}



