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


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    string s, t;
    cin >> s >> t;
    
    string fs, ft;
    
    
    for(int i=0;i<t.length();i++){
        fs += s;
    }
    // t의 횟수만큼 s를 더해줌
    for(int i=0;i<s.length();i++){
        ft += t;
    }
    // s의 갯수만큼 t에 더해줌
    
    if(fs == ft)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
    
    return 0;
    
}
