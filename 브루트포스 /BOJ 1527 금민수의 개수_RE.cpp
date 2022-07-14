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

ll ans = 0;
ll a, b;
void find(ll num){
    if(num > b)
        return;
    if(num >= a && num <= b)
        ans++;
    // b보다 크면 리턴하고 주어진 조건에 맞으면 ans를 증가시킨다.
    
    find(num * 10 + 4);
    find(num * 10 + 7);
    // 4와 7로 만 이루어지기 위해서 하나를 올린뒤 4,7로 더한다.
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> a >> b;
    
    find(4);
    find(7);
    // 각각 4, 7부터 시작한다.
    
    cout << ans;
    
    
    return 0;

}
