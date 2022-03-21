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

    
    while(1){
        int a, b, c;
        cin >> a >> b >> c;
        
        if(a == 0 && b == 0 && c == 0)
            break;
        
        if(a + b <= c || b + c <= a || c + a <= b)
            cout << "Invalid" << '\n';
        else if(a == b && b == c && c == a)
            cout << "Equilateral" << '\n';
        else if(a == b && b != c && c != a)
            cout << "Isosceles" << '\n';
        else if(a == c && b != c && b != a)
            cout << "Isosceles" << '\n';
        else if(c == b && a != c && c != a)
            cout << "Isosceles" << '\n';
        else if(a != b && b != c && c != a)
            cout << "Scalene" << '\n';
        
    }
    
    
    
    
    
    return 0;

}
