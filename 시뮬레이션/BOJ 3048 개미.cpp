
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


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n1, n2;
    cin >> n1 >> n2;
    
    string st1, st2;
    
    cin >> st1 >> st2;
    reverse(st1.begin(), st1.end());
    // st1을 거꾸로 해서 st2와 붙여서 새로운 스트링을 만든다.
    string str = st1 + st2;
    
    cin >> t;
    int cnt = 0;
    
    
    while(cnt < t){
        for(int i=0;i<n1+n2-1;i++){
            if(st1.find(str[i]) != string::npos && st2.find(str[i+1]) != string::npos){
                // 여기서 string::npos는 찾는 문자열이 없을 경우 string::npos를 반환하는데
                // 여기서 둘다 있을 경우 아래를 바꾸는 것이다.
                swap(str[i], str[i+1]);
                i++;
            }
        }
        cnt++;
    }
    
    cout << str;

    
    return 0;
}


// 솔직히 시뮬레이션은 문제도 이해가 안가고, 푸는 것도 잘 모르겟군...
// 나중에 다시 또 풀어봐야겟다..
