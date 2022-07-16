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



bool check(int now, bool button[10]){
    string st = to_string(now);
    for(int i=0;i<st.length();i++){
        if(button[st[i] - 48])      // true일 경우 안되므로 false
            return false;
    }
    return true;                // now의 모든 문자를 조사하여 되면 true
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bool button[10] = {false};
    // 기본적으로 모두 된다는 것 = false
    
    cin >> n;
    cin >> m;
    for(int i=0;i<m;i++){
        int a;
        cin >> a;
        button[a] = true;
        // true의 경우 안된다는 것
    }
    
    string st = to_string(n);
    int Min = abs(n - 100);
    // 처음 숫자인 100과 n을 비교하여 최대를 Min으로
    // 그냥 100에서의 차이를 최대로 설정
    
    for(int i=0;i<=1000000;i++){
        if(check(i, button)){
            int num = abs(n - i) + to_string(i).length();   // 차이와 길이를 더해서 num에
            //            차이           i의 자리수
            Min = min(Min, num);
            // n-i와 i의 길이를 구함
        }
    }
    
    cout << Min;
    
    return 0;

}
