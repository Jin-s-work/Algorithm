#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    return a + b > b + a;
}
// 내림차순 정렬 문자열도 해야 하므로 이런식으로
// 밑에 구현은 다 했는데 이 부부닝 아쉽게 되었음

string solution(vector<int> numbers) {
    string answer = "";
    
    // 10의 자리만 확인..?
    vector<string>v;
    
    for(int i=0;i<numbers.size();i++){
        v.push_back(to_string(numbers[i]));
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0;i<v.size();i++){
        answer += v[i];
    }
    
    if(answer[0] == '0')
        return "0";
    // 제일 큰 부분 즉 제일 앞에 있는 부분이 0일 경우 그냥 0으로 나오게 한다.
    // 이렇게 안하면 00 000 이런식을 될 수도 있다.
    // ** 이 부분을 고려하지 못함 **
    
    return answer;
}

// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// bool cmp(string a, string b){
//     return a + b > b + a;
// }
// // 함수는 {}를 생략하면 안되고 그대로 적어줘야 한다.
// // 서로 같이 문자열로 추가를 해서 a+b가 b+a보다 크게 정렬

// string solution(vector<int> numbers) {
//     string answer = "";
    
//     vector<string>v;
//     for(int i=0;i<numbers.size();i++){
//         v.push_back(to_string(numbers[i]));
//     }
    
//     sort(v.begin(), v.end(), cmp);
//     // 합하였을때 문자열이 제일 크게 비교
    
//     for(int i=0;i<v.size();i++)
//         answer += v[i];
//     // 각각 넣어주면 끝
    
//     if(answer[0] == '0')
//         return "0";
    
    
//     return answer;
// }

















