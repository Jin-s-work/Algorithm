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





int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    int sum = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            sum += i + j;
        }
    }
    
    cout << sum;
    
    
    return 0;

}
