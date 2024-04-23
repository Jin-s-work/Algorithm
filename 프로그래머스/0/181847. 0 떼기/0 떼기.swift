import Foundation

func solution(_ n_str:String) -> String {
    
    let chars = Array(n_str)
    
    var startIndex = 0
    for char in chars {
        if char == "0" {
            startIndex += 1
        } else {
            break
        }
    }
    
    return String(chars[startIndex...])
}