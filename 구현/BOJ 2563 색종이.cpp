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

// control i
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;



int arr[100][100];      // 밖으로 나가면 안되므로 100까지
// main안에 놓는것과 밖에 놓는 값이 다르다...

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        for(int j=a;j<a+10;j++){
            for(int k=b;k<b+10;k++){
                if(!arr[j][k]){
                    arr[j][k] = 1;
                    ans++;
                }
            }
        }
    }
    
    
    cout << ans;
    
    
    return 0;

}
