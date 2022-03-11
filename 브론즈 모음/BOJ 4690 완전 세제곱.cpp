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

    
    for(int i=6;i<=100;i++){
        for(int j=2;j<i;j++){
            for(int k=j+1;k<i;k++){
                for(int l=k+1;l<i;l++){
                    if(i*i*i == j*j*j + k*k*k + l*l*l)
                        cout << "Cube = " << i << ", Triple = (" << j << "," << k << ',' << l << ")\n";
                }
            }
        }
    }

    
    
    
    return 0;

}
