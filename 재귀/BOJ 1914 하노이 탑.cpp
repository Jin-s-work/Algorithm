
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
int h;


void hanoi(int num, int start, int path, int end){
    if(num == 1)
        cout << start << " " << end << '\n';        // 1일 경우에는 그냥 출력
    else{
        hanoi(num-1, start, end, path);             // 아닐 경우에는 num을 빼가면서 횟수줄임
        // n-1개를 모두 path로 보내고
        cout << start << " " << end << '\n';        // 바꾸어 가면서 해줌
        hanoi(num-1, path, start, end);
        // 다음은 n-1개를 path에서 end로 보내줌
    }
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    string st = to_string(pow(2, n));   // pow가 double형으로 무조건 나우므로
    // n이 100까지 가능하므로 수가 너무 커질 수가 있어서 문자열로 해야 한다.
    
    int tmp = st.find('.');
    // 그냥 pow(2, n)으로 하면 소수점으로 나뉘어서 이렇게 한다. (pow가 무조건 double형)
    st = st.substr(0, tmp);
    // substr로 소수점까지 읽어서 소수점 빼줌
    
    st[st.length() - 1] -= 1;
    // 맨마지막 뒤의 수 즉 일의 자리수에서 1빼줌
    
    cout << st << '\n';
    
    if(n <= 20)
        hanoi(n, 1, 2, 3);      // n개의 원판 중 1번과 2번과 3번
    
    
    
    return 0;
}

