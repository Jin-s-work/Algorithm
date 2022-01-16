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


int arr[100001];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        cin >> k;
        arr[i] = arr[i-1] + k;
    }
    
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        int sum = arr[b] - arr[a-1];
        cout << sum << '\n';
    }
    
    
    

    return 0;

}
