func majorityElement(nums []int) int {
    // count := 0
    var element, count int;

    for _, v := range nums{
        if count == 0{
            element = v
        }
        
        if v == element {
            count++
        } else{
            count--
        }
    }

    return element
}