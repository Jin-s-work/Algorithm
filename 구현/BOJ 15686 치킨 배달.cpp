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


int arr[51][51];
int dist(pair<int, int>a, pair<int, int>b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}
bool check[14];
vector<pair<int, int>>v1;       // 집
vector<pair<int, int>>v2;       // 치킨
int ans = 0;

void DFS(int idx, int num){
    if(num == m){           // 마침내 m이 되었을 경우에
        int res = 0;
        for(int i=0;i<v1.size();i++){       // 한 집에 관해서
            int distance = MAX;
            for(int j=0;j<v2.size();j++){   // 치킨을 돈다
                if(check[j])                // true일 경우
                    distance = min(distance, dist(v1[i], v2[j]));
            }                               // 최소의 distance를 구한다.
            res += distance;                // 치킨 집의 결과를 ans에 더한다.
        }
        
        ans = min(ans, res);                // 작은지 확인하기
        return;
    }
    
    if(idx == v2.size())            // 치킨집의 개수와 인덱스랑 같으면 리턴
        return;
    
    // 되는 곳 찾기
    check[idx] = true;
    // idx는 치킨집들 개수라고 생각하면 됨 즉 첫번째 치킨 집을 true로 하고 distance 비교
    DFS(idx + 1, num + 1);          // 하나씩 늘리고 DFS (DFS는 계속 파고드므로 여기에 놓기)
    // 안되는 곳
    check[idx] = false;         // 리턴 될 경우 여기로 와서 false를 표시해준다.
    DFS(idx + 1, num);          // 그리고 idx를 늘려서 다시 시도
    
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                v1.push_back({i, j});
            }
            else if(arr[i][j] == 2)
                v2.push_back({i, j});
        }
    }
    
    // 도시의 치킨 거리는 모든 집의 치킨 거리의 합
    // 치킨 거리 : 집과 가장 가까운 치킨집 사이의 거리
    
    // DFS로 푸는 방식이었는데 내가 푸려던 방향과는 같았지만, DFS를 제대로 생각못했다..
    
    ans = MAX;
    DFS(0,0);
    cout << ans;
    
    
    
    
    return 0;

}
