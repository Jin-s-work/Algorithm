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




int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n1, n2;
    cin >> n1 >> n2;
    
    string st1, st2;
    cin >> st1;
    cin >> st2;
    
    cin >> t;

    reverse(st1.begin(), st1.end());
    string ans;
    
    ans = st1 + st2;
    
    
    int num = 0;
    while(num < t){
        for(int i=0;i<n1+n2-1;i++){
            if(st1.find(ans[i]) != string::npos && st2.find(ans[i+1]) != string::npos){
                swap(ans[i], ans[i+1]);             // 둘다 다를 경우 바꾸어줌
                i++;
            }           // 그 시간일때 다른 접접들이 있으면 바꾸어줌
        }
        num++;      // 다음 시간으로 넘어감

    }
    
    cout << ans << '\n';
    
    return 0;

}
