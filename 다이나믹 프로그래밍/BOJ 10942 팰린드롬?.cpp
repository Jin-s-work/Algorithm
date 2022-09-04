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
#define mod 1000000000
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


int arr[2001];
bool check[2001][2001] = {false,};

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    
    for(int i=1;i<=n-1;i++){
        if(arr[i] == arr[i+1])
            check[i][i+1] = true;
    }   // 만약에 i와 i+1이 같을 경우 true로
    // 즉, 하나 차이인 경우도 팰린드롬이므로 고려해주어야 한다.
    
    for(int i=1;i<=n;i++){
        check[i][i] = true;
    }   // 같은 경우는 무조건 true
    
    for(int i=n-1;i>=1;i--){        // i는 뒤에서 앞으로 오고
        for(int j=i+2;j<=n;j++){    // j는 앞에서 뒤로 간다.
            if(arr[i] == arr[j] && check[i+1][j-1])     // check를 할때는 왼쪽으로 가는거는 +1
                check[i][j] = true;                     // 오른쪽으로 가는 것은 -1
        }
        // i - j까지가 팰린드롬이려면 i+1 ~ j-1도 팰린드롬이어야 성립한다.
        // 여기서는 i와 j자체만을 비교해 주고 있기 때문에 가운데들도 고려해주어서 &&로 해주어야 한다.
    }
    //    o x x x o
    //  양 끝이 되더라도 중간 부분들이 안되면 안되므로 check는 i+1 j-1를 체크해야한다.
    //  범위에 맞추어 n-1 - 1 과 i+2 - n 의 범위로
    
    
    cin >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        
        cout << check[a][b] << '\n';
    }
    
    
    
    
    return 0;
    
}
