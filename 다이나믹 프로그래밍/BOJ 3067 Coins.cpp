

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

    
    cin >> t;
    int c[21] = {0};

    
    while(t--){
        
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> c[i];
        }
        
        cin >> m;
        
        int arr[10001] = {0};
        arr[0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=c[i];j<=m;j++){
                arr[j] += arr[j - c[i]];
                // j가 c[i]부터 m까지 이므로
                // arr[c[i]] += arr[0] 부터
                // arr[m] += arr[m - c[i]]
            }
        }
        
        cout << arr[m] << '\n';
        
        
        
        
    }
    
    
    
    
    
    return 0;

}


