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


int dp[100001][5][5];
int num;
vector<int>v;

int dist(int a, int b){
    if(a == 0 || b == 0)
        return 2;
    
    int dif = abs(a - b);
    if(dif == 0)
        return 1;
    else if(dif == 1 || dif == 3)
        return 3;
    else if(dif == 2)
        return 4;
    
    return 0;
}

int DFS(int now, int left, int right){
    if(now == num)
        return 0;
    // 지금과 num이 같으면 그냥 0
    if(dp[now][left][right] != -1)
        return dp[now][left][right];
    // -1이 아닐 경우 그 값에 맞게 리턴한다.
    
    int left_tmp = DFS(now + 1, v[now], right) + dist(v[now], left);
    int right_tmp = DFS(now + 1, left, v[now]) + dist(v[now], right);
    // 왼쪽부분은 v[now]와 left의 거리와 left가 이동한 값으로
    // 오른쪽부분은 v[now]와 right의 거리와 right가 이동한 값으로
    
    return dp[now][left][right] = min(left_tmp, right_tmp);
    // 둘 중에 최소값을 넣어준다.
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        
        cin >> n;
        
        if(n == 0){
            break;
        }
        
        v.push_back(n);
    }
    
    memset(dp, -1, sizeof(dp));
    num = v.size();
    cout << DFS(0,0,0);
    
    
    

    return 0;

}


// 중앙에서 다른 곳으로 : 2
// 다른 지점에서 인접한 지점으로 : 3
// 아예 반대편 지점으로 : 4
// 같은 지점 한번 더 누르기 : 1

// 1 2 2 4 0
// 2 2 1 3
