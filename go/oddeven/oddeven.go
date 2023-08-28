package main

import "fmt"

func main(){
    ch1:=make(chan int)
	ch2:=make(chan int)
	go Odd(ch1)
	go Even(ch2)
	for i:=0;i<=10;i++{
       if i%2==0{
		ch2<-i
	   }else{
		ch1<-i
	   }
	}
}

func Odd(ch <-chan int){
	for i:=range ch{
		fmt.Println(i,":Odd")
	}
}

func Even(ch <-chan int){
	for i:=range ch{
		fmt.Println(i,":Even")
	}
}