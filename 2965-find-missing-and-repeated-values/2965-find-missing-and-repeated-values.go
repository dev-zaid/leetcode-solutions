func findMissingAndRepeatedValues(grid [][]int) []int {
    var sum,repeatedNum int;
    n := len(grid) * len(grid) // n^2
    expSum:= n*(n+1)/2

    seen := make(map[int]struct{})

    for _,row := range grid{
        for _,v := range row{
            sum += v
            _,exists := seen[v]

            if exists{
                repeatedNum = v
            } else{
                seen[v] = struct{}{}
            }
        }
    }

    // expSum = actualSum - repeatedNum + missingNumber

    missingNumber := expSum - sum + repeatedNum;

    return []int{repeatedNum, missingNumber}
}