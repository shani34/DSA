package main

import (
	"fmt"
	"time"
)

func foo(s string){
	for i:=0;i<3;i++{
		time.Sleep(100*time.Millisecond)
		fmt.Println(s,"",i)
	}
}

func bar(s string){
	for i:=0;i<3;i++{
		time.Sleep(100*time.Millisecond)
		fmt.Println(s,"",i)
	}
}

func usingChannel2(ch chan int){
	for i:=0;i<5;i++{
		ch<-i
	}

	close(ch)

	//one way to fix the deadlock problem
}

func usingChannel1(ch chan int){
	
	for i:=0;i<5;i++{
		ch<-i*i
	}

	close(ch)
	
	//one way to fix the deadlock problem
}

func main(){
// fmt.Println("main started")
// go foo("shani")
// go bar("kumar")

// time.Sleep(time.Second)
// fmt.Println("main end")

ch:=make(chan int)
ch1:=make(chan int)
//basic principal of go routines is that they get blocked by channels when they are not close 
//or trying to read every channel to unblock the go routines
go usingChannel1(ch)
go usingChannel2(ch1)

//read from the channel
for i:=0;i<5;i++{
	fmt.Println(<-ch)
}

//read from the channel 
for i:=0;i<5;i++{
	fmt.Println(<-ch1)
}


// for i:=0;i<7;i++{
// 	fmt.Println(<-ch)
// }


}

