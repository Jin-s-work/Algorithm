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

    
    string st;
    cin >> st;
    
    if(next_permutation(st.begin(), st.end())){
        cout << st;
    }
    else
        cout << '0';
    
    // 그냥 다음 순열을 찾는 것 이므로, next_permutation으로 해서 있으면 다음의 st를 출력하고
    // 아니면 0을 그냥 출력한다.
    
    
    return 0;

}


