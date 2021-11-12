
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

int arr[201][201];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        arr[a][b]++;
        arr[b][a]++;
    }
    
    int sum = 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(arr[i][j])
                continue;
            // 하나라도 있으면 true이므로 continue
            for(int k=j+1;k<=n;k++){
                if(arr[i][k] || arr[j][k])
                    continue;
                // 3가지 이므로 한 번 더해서 i,j와 연관이 있으면 그냥 continue
                sum++;
                // 다 넘었을 경우 한 가지 경우의 수이다.
            }
        }
    }
    
    cout << sum;
    
    return 0;
}




