
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

vector<int>v;
int ans = 0;

void DFS(int num, int digit){
    if(num > n)
        return;
    // num이 n보다 커질 경우 그냥 커지고, ans는 그 전가지의 최대를 가짐
    
    ans = max(ans, num);
    // ans 중 제일 큰 것으로 갱신
    
    for(int i=0;i<v.size();i++){
        DFS(num + digit * v[i], digit * 10);
        // 만드는 숫자에 자리수를 더해주면서 커진다. v의 size는 보통 3보다 작으므로 괜찮다.
        // 따라서 3자리수 까지 가능
    }
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> k;
    
    for(int i=0;i<k;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end());
    
    DFS(0,1);
    // 숫자는 0 자리수는 1
    
    cout << ans;
    
    
    return 0;
}


// 전에 푼 카드 놓기를 생각하여 코드를 구성해 보았으나, 이 부분은 원소를 중복적으로 사용하지 못하는 것 같아
// 수정해보아야겠다.

// 중복순열은 next_permutation을 사용하지 않고, DFS를 사용하면 간단하게 표현 할 수 있었다.

