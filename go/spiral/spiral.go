package main

import "fmt"
func Spiral(matrix [][]int ){
	n:=len(matrix)
	left, top,right,bottom:=0,0,n-1,n-1

	for left<right && top<bottom{
		//printing first row
		for i:=left;i<=right;i++{
			fmt.Printf("%v\t ",matrix[top][i])
		}
		top++

		// printing last column
		for i:=top;i<=bottom;i++{
			fmt.Printf("%v\t ",matrix[i][right])
		}
		right--

     //printing the bottom 
	 if (top<bottom){
		 for i:=right-left;i>=left;i--{
			fmt.Printf("%v\t ",matrix[bottom-left][i])
		 }
		 bottom--
	 }

	 // printing first column
	 if left<right{
		for i:=bottom-left;i>=top;i--{
			fmt.Printf("%v\t ",matrix[i][left])
		 }
		 left++
	 }
	}
}

func main(){

	matrix:=[][]int{
		{1,2,3,4},
		{5,6,7,8},
		{3,4,5,6},
		{6,7,7,9},

	}
	Spiral(matrix)
}