import Foundation

func solution(_ num_list:[Int]) -> [Int] {
    
    var arr = num_list
    let lastIndex = num_list.count - 1
    
    if lastIndex > 0 && num_list[lastIndex] > num_list[lastIndex - 1] {
        arr.append(num_list[lastIndex] - num_list[lastIndex - 1])
    } else {
        arr.append(num_list[lastIndex] * 2)
    }
    
    // var arr : [Int] = []
    // for i in 0..<num_list.count-1{
    //     if i == num_list.count - 2{
    //         if num_list[i] < num_list[i+1]{
    //             arr.append(num_list[i])
    //             arr.append(num_list[i+1])
    //             arr.append(num_list[i+1] - num_list[i])
    //         }
    //         else if num_list[i] > num_list[i+1]{
    //             arr.append(num_list[i])
    //             arr.append(num_list[i+1])
    //             arr.append(num_list[i+1] * 2)
    //         }
    //     }
    //     // else if i == num_list.count - 1{
    //     //     continue
    //     // }
    //     else{
    //         arr.append(num_list[i])
    //     }
    // }
    
    return arr
}