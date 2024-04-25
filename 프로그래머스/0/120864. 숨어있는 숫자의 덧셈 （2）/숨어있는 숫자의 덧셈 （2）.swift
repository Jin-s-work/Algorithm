import Foundation

func solution(_ my_string:String) -> Int {
    
//     var ans = 0
//     var st = ""
//     for k in my_string{
//         if k.isNumber{
//             st.append(k)
//         }
//         else{
//             if let num = Int(st){
//                 ans += num
//                 st = ""
//             }
//         }        
//     }
    
//     if let num == Int(st){
//         ans += num
//     }
    var sum = 0
    var numStr = ""

    for char in my_string {
        if char.isNumber {
            numStr.append(char)
        } else {
            if let num = Int(numStr) {
                sum += num
                numStr = ""  
            }
        }
    }

    if let num = Int(numStr) {
        sum += num
    }
    
    return sum
}