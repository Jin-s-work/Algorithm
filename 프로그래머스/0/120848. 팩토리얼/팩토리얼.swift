import Foundation

func solution(_ n:Int) -> Int {
    
    var num = 1
    var i = 1
    while num <= n{
        i += 1
        num *= i
    }

//     func fac(num : Int) -> Int{
//         var res = 1
//         for i in 1...num{
//             res *= i
//         }
//         return res
//     }
    
//     var ans = 0
//     for i in 1...n{
//         if fac(num : i) > n{
//             ans = i - 1
//             break
//         }
//     }
    
    return i-1
}