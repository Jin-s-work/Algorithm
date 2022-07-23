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

// control i처
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

    
    cin >> n;
    int s;
    cin >> s;
    
    vector<int>v;
    
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    int a = 0;
    int b = 0;
    int Min = MAX;
    ll sum = v[0];
    // 처음의 sum은 v의 첫번째로 지정한다.
    
    while(a <= b && b < n){     // a가 b 이하이고, b도 범위를 안 넘을 때
        if(sum > s){
            Min = min(Min, b - a + 1);      // 이상이 될 경우에 찾아주는 것이므로
            // 길이를 비교하여 짧은 값을 넣어주기
            sum = sum - v[a++];
            // a++를 통해 빼주고 a는 증가시킴
            // 빼주는 것은 즉 다음 값으로 넘어가는 것
            // 왜냐하면 커질 경우 작게 해줘야 하므로
        }
        else if(sum < s)                    // 미만인 경우에는 그냥 합을 새로 더해주고 넘어감
            sum = sum + v[++b];
        // 더할 경우에는 b를 증가시키고 더해준다.
        else{       // 같은 경우
            int c = b - a + 1;
            Min = min(Min, c);      // 같은 경우도 해당되기에 최소인지 비교하고 넣어주어야함
            sum = sum + v[++b];     // 더 커져도 되므로 넣어준다.
        }
        
    }
    
    if(Min == MAX)
        cout << 0 << '\n';
    else
        cout << Min << '\n';
    
    
    
    return 0;

}
