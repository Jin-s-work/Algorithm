
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string st(int d, int n){
    string s = "";
    char code[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    
    while(d/n != 0){
        s = code[d%n] + s;
        // 나눈 나머지에 맞는 숫자를 string에 추가한다.
        
        d /= n;
    }
    s = code[d%n] + s;
    // 마지막 남은 것 까지
    
    return s;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string tmp = "";
    
    for(int i=0;i<t*m;i++){
        tmp += st(i,n);
    }
    // 말해야 하는 숫자의 개수(t) * 게임에 참가하는 인원수 (m)
    
    int num = 0;
    
    // p-1부터 tmp의 크기만큼
    // tmp[i]를 하나씩 더해준다.
    for(int i=p-1;i<tmp.size();i+=m){
        answer += tmp[i];
        if(num+1 == t)
            break;
        // 즉 num이 0-(t-1)까지
        num++;
    }
    
    
    return answer;
}












// 실패한 처음 방법... 문제 이해를 잘 못한 듯
//
//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//string dec(int num, int d){
//    string st = "";
//
//    while(num){
//        st += to_string(num % d);
//        num /= d;
//    }
//
//    return st;
//}
//
//
//
//string solution(int n, int t, int m, int p) {
//    string answer = "";
//    string tmp = "";
//
//    string st = "";
//
//
//    dec(t, n);
//
//
//
//    return answer;
//}
