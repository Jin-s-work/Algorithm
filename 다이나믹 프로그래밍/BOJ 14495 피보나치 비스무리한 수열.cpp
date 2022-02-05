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


ll arr[117];
// long long을 안해서 틀림.. 바보


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;
    
    cin >> n;
    
    
    for(int i=4;i<=n;i++){
        arr[i] = arr[i-1] + arr[i-3];
    }
    
    cout << arr[n];
    
    
    
    return 0;

}


