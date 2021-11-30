

#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    int num = 0;
    int mon[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string day[8] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    
    for(int i=0;i<a-1;i++){
        num += mon[i];
    }
    // a가 달이므로, 그에 따라 전까지 날짜들을 더해준다.
    
    num += b - 1;
    answer = day[num % 7];
    // num에 b-1로 그 날까지 수를 더해주고
    // num % 7로 하여 1이면 금요일이므로 나머지를 활용하여 한다.
    
    return answer;
}













