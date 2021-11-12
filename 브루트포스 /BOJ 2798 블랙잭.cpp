
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
    
    cin >> n >> m;
    
    int arr[101];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    int Max = 0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                int sum = 0;
                sum += arr[i] + arr[j] + arr[k];
                if(sum <= m && m - sum < m - Max)
                    Max = sum;
            }       // 합이 m보다 작아야 하는 걸 넣어야 함
        }
    }
    
    cout << Max;
    
    
    
    return 0;
}


