#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int ans = 0;
    int ans2 = 0;
    string str;
    
    while(s != "1"){
        
        int one = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '1')
                one++;
            else if(s[i] == '0')
                ans++;
        }
    
    // 2 | 4  0
    // 2 | 2  0
    //     1
    
        s = "";
        while(one > 0){
            if(one % 2 == 0)
                s += "0";
            else
                s += "1";
        
            one /= 2;
        }
        // v 자체는 int 이므로 string으로 해줘야할듯
        
        // ** 원래 여기서 s가 거꾸로 아마 들어가는데 이렇게 하고 끝내도 되는 것은
        // 숫자 자체가 의미가 있는 것이 아니라 계속 그냥 1의 길이에 따라 바뀌므로
        // 순서는 상관없기 때문이다 **
        
        // 0 0 1
        
        // bool check = false;
        // for(int i=str.size()-1;i>=0;i--){
        //     s += str[i];
        //     if(str[i] == '0')
        //         check = true;
        // }
        
        ans2++;
        
        // if(!check)
        //     break;
        
    }
    
    answer.push_back(ans2);
    answer.push_back(ans);
    
    
    return answer;
}


// #include <string>
// #include <vector>

// using namespace std;

// vector<int> solution(string s) {
//     vector<int> answer;
    
//     int sum = 0;
//     int num = 0;
    
//     while(s != "1"){
//         int cnt = 0;
//         for(int i=0;i<s.length();i++){
//             if(s[i] == '1')
//             cnt++;
//         }
        
//         sum += s.length() - cnt;        // 1 빼면 0이므로
        
//         s = "";     // 초기화
//         while(cnt > 0){
//             if(cnt % 2 == 0)
//                 s += "0";
//             else
//                 s += "1";
//             cnt /= 2;
//         }
        
//         num++;
    
//     }
    
//     answer.push_back(num);      // 2진 번환의 횟수
//     answer.push_back(sum);      // 제거된 모든 0의 개수
    
//     return answer;
// }


// // 이진법으로 하려면 reverse를 해야 하지만 0의 개수, 1의 개수만 알면 되므로

