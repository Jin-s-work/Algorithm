import Foundation

func solution(_ myString:String, _ pat:String) -> Int {
    
    var ans = 0
    for i in 0...myString.count-pat.count{
        let st = String(myString[myString.index(myString.startIndex, offsetBy: i)..<myString.index(myString.startIndex, offsetBy: i + pat.count)])

        if st == pat{
            ans += 1
        }
    }
    
    return ans
}