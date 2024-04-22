import Foundation

func solution(_ my_string:String) -> Int {
    
    var s = 0
    for k in my_string{
        if let number = Int(String(k)) {
            s += number
        }
    }
    
    return s
}