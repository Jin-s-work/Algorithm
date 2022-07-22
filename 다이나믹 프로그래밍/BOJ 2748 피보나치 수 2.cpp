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

// control i처
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;



ll arr[101];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    for(int i=0;i<n-1;i++){
        arr[i+2] = arr[i+1] + arr[i];
    }
    
    cout << arr[n];
    
    
    
    return 0;

}
