
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


vector<pair<ll, ll>>v;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    ll sum = 0;
    
    for(int i=0;i<n;i++){
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
        sum += b;
    }
    
    sort(v.begin(), v.end());
    
    ll num = 0;
    for(int i=0;i<n;i++){
        num += v[i].second;     // 각각 인원의 수를 더해 가면서, (전체합+1)/2 가 될때까지 확인
        if(num >= (sum + 1)/2){
            // 모든 인원을 더한 sum의 중간보다 num이 커질 경우 거기가 거리의 합이 최소가 되므로 거기로 한다.
            cout << v[i].first << '\n';
            break;
        }
    }
    
    // 각 사람까지의 거리 합이므로, 사람 수에 따라 비중이 달라지기에
    // 각 사람들을 더한 합 + 1 /2 보다 커질때 딱 그 순간이 거리의 합이 최소가 될것이다.
    
    return 0;
}


// 솔직히 바로 생각이 안나서 찾아보고 풀었다.
// 범위가 너무 커서 어떻게 해야할지 몰랐는데, 마지막, sum+1/2 부분을 참조하여 풀게 되었다.
// 수학관데 이 정도는 해야할듯..
