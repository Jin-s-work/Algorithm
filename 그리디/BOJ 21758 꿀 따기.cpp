
#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>
#include <map>
#include <set>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,k;
int l,r,t;
int h, w;


vector<int>v;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    int sum = 0;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
        sum += a;
    }
    
    int ans = 0;
    int honey = 0;
    
    for(int i=1;i<n;i++){
        honey = v[i];
        ans = max(ans, sum - v[0] - v[n-1] + honey);
    }
    // 여기서는 벌이 양 끝에 있고, 꿀이 중간에 껴있는데, 꿀이 중간에서 왔다갔다 하는 것
    // 벌은 무조건 양 끝에 있어야 좋다.
    
    honey = v[n-1];
    for(int i=n-2;i>0;i--){
        ans = max(ans, sum - v[0] - v[i] + honey);
        honey += v[i];
        // 여기서 v를 왼쪽으로 옮기면서 얻는 이익이 v[원래 자리]*2 만큼 생기는데
        // sum에서 각각 빼는 형식보다 따라서 v[i]만큼이 더 증가하기에 더해준다.
    }
    // 이 경우는 꿀을 맨 끝에 놓는 경우
    
    honey = v[0];
    for(int i=1;i<n-1;i++){
        ans = max(ans, sum - v[n-1] - v[i] + honey);
        honey += v[i];
        // 위와 같은 이유이다.
    }
    // 이 경우는 꿀을 맨 앞에 놓는 경우
    
    cout << ans;
    
    return 0;
}


// 경우를 하나하나 해서 세가지로 추려서 구해야 하는 상황이다.
// 벌을 옮길 때, 2배가 증가하므로, 차를 이용하여 구할 때 밑에서 더해주어야 하는 것이 포인트..!
// 솔직히 처음 보고 생각하기 힘든거 같지만, 구현처럼 상세히 보면 할 수 있을 거 같기도 하다.
