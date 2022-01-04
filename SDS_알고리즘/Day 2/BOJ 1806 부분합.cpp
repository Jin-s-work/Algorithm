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
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
ll n,m,k;
int l,r,t;
int h;



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    int s;
    cin >> n >> s;
    
    vector<int>v;
    
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    int a = 0;
    int b = 0;
    int Min = MAX;
    ll sum = v[0];
    
    while(a <= b && b < n){
        
        if(sum > s){
            Min = min(Min, b - a + 1);
            sum = sum - v[a++];
        }
        else if(sum < s){       // 작은 경우는 그냥 sum만 더해준다.
            sum = sum + v[++b];
        }
        else{           // 같은 경우는 b를 늘려준다.
            int c = b - a + 1;
            Min = min(c, Min);
            sum = sum + v[++b];
        }               // 같으므로 sum도 더해다 줌
        
    }
    
    if(Min == MAX)
        cout << 0 << '\n';
    else
        cout << Min << '\n';
    
    
    return 0;

}
