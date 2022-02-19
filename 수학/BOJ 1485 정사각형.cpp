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

ll a[4], b[4], arr[6];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> t;
    
    while(t--){
        
        num = 0;
        for(int i=0;i<4;i++){
            cin >> a[i] >> b[i];
        }
        
        for(int i=0;i<4;i++){
            for(int j=i+1;j<4;j++){
                arr[num] = (a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j]);
                num++;
            }
        }
        
        sort(arr, arr + 6);
        cout << (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3] && arr[4] == arr[5]) << '\n';
        
    }
    
    
    return 0;

}
