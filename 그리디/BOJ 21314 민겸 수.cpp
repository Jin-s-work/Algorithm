
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
int n,k;
int l,r,t;
int h, w;



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string st;
    cin >> st;
    
    ll m = 0;
    
    string Max = "";
    string Min = "";
    for(ll i=0;i<st.size();i++){
        
        if(st[i] == 'M'){
            m++;
        }
        
        if(st[i] == 'K'){
            if(m){
//                Max += to_string(int((pow(10, m)) * 5));
                Max += "5";
                for(int i=0;i<m;i++){
                    Max += "0";
                }
                Min += "1";
                for(int i=0;i<m-1;i++){
                    Min += "0";
                }
                Min += "5";
//                Min += to_string(int(pow(10, m)) + 5);
            }
            else{
                Max += "5";
                Min += "5";
            }
            m = 0;
            // K로 M 처리를 해주었으면 다시 0으로 해서 초기화
        }
        
    }
    
    // 만약 끝났는데 M이 남아있을 경우 더 더해줘야한다.
    if(m){
        Min += "1";
        for(int i=0;i<m-1;i++){
            Min += "0";
        }
//        Min += to_string(int(pow(10, m-1)));
        
        while(m){
            Max += "1";
            m -= 1;
        }
    }
    
    cout << Max << '\n' << Min;
    
    return 0;
}


// 최대 최소를 따로 구해보자.

// 답은 나오지만 pow를 사용하면 double로 되서 해결방법 찾는중..
// 그냥 주변을 int로 싸주니까 된다..?
// 구글링해도 코드가 안나와서 내가 함....
// 답은 맞는거 같아 양식을 봐야겠다.

// 계속 찾아도 안되었는데, 알고보니 to_string으로 할때, 10^n이 너무 커서 string으로 바로 해야했던 것
// 따라서 string을 각각 넣어주기
