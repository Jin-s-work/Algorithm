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


vector<int>v;
int ans = 0;

void DFS(int num, int digit){
    if(num > n)
        return;
    // n보다 클 경우 그냥 return
    
    ans = max(ans, num);
    // 더 큰 num으로 갱신
    
    for(int i=0;i<v.size();i++){
        DFS(num + digit * v[i], digit * 10);
    }
    // DFS를 통하여 다음 숫자는 이번에 쓴 수에 자리수를 더해 앞 자리수를 늘려간다.
    // DFS이므로 이런식으로 계속 파고들면서 중복을 허용해서 하는 것이다.
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> k;
    
    for(int i=0;i<k;i++){
        ll a;
        cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end());
    
    DFS(0, 1);
    
    cout << ans;
    
    
    
    return 0;

}

// next_permutation 으로 처음 풀었으나 이것은 중복이 되지 않아, DFS를 활용하기
