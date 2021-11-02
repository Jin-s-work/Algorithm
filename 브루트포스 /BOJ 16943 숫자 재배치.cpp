
#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>
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


vector<int>v;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string a;
    cin >> a;
    
    int b;
    cin >> b;
    sort(a.begin(), a.end());
    
    int ans = -1;
    
    do{
        
        int c = stoi(a);
        if(a[0] != '0' && c <= b){      // 앞이 0이면 안되고, c는 b보다 항상 작아야 한다.
            if(ans < c || ans == -1)    // ans가 -1이거나 c보다 작을 경우
                ans = c;                // ans를 c로 갱신해준다.
        }
        
    }while(next_permutation(a.begin(), a.end()));
    // 순열로 찾아준다.

    cout << ans;
    
    return 0;
}


// 원래 벡터로 풀다가 내가 보기엔 for문에서 범위를 잘못 설정해준 것 같은데 아무튼 안되서
// 부랴부랴 string으로 해서 하긴 했는데 다시 해봐야겠다.....
// string이 더 간단하긴 한데,,, 벡터도 알아봐야겟다
