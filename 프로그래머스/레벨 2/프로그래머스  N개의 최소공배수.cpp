

#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    int c;
    while(b){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcd(int a, int b){
    return (a * b) / gcd(a, b);
}


int solution(vector<int> arr) {
    int answer = 0;
    
    answer = lcd(arr[0], arr[1]);
    
    for(int i=2;i<arr.size();i++){
        answer = lcd(answer, arr[i]);
    }
    
    
    return answer;
}













