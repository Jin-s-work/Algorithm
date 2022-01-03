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
int n,m,k;
int l,r,t;
int h;



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    
    cin >> n;
    
    cout << (n / 100) * 78 << " ";
    
    int num = 0.8 * n;
    
    ll res = 0.2 * n;
    
    cout << (int)(num + res * 0.78) << '\n';
    // int를 붙여줘야 e형으로 안나오고 그냥 int형으로 나온다.
    
    
    

    return 0;

}

