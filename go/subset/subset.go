package main

import (
	"fmt"
	"sort"
)

// type ans []int
func threeSum(nums []int) [][]int {
    target:=0
    n:=len(nums)
    sort.Ints(nums)
     ans:=make([][]int,0)
    for i:=0;i<n;i++{
        tmp:=make([]int,0)
        target-=nums[i]
        l:=i+1;h:=n-1
        for l<h {
            if nums[l]<target{
                l++
            }else if nums[l]>target{
                h--
            }else{
                tmp=append(tmp, nums[i],nums[l],nums[h])
				l++
				h--
            }
        }
		if len(tmp)!=0{
        ans=append(ans,tmp)
		}
    }

    return ans
}

func main(){
	input:=[]int{0,0,0}

	fmt.Println(threeSum(input))
}