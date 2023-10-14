package main

import (
	 "math/rand"
	"fmt"
	"time"
)


//But real commmunication is not happening between these two go routines
func Boring(msg string){

	for i:=0; ;i++{
		fmt.Println(msg,i)
		time.Sleep(time.Duration(rand.Intn(1e3))*time.Millisecond)
	}
}

func boring(msg string, ch chan string){

	for i:=0; ;i++{
		ch<-fmt.Sprintf("%s, %d",msg, i)
		time.Sleep(time.Duration(rand.Intn(1e3))*time.Millisecond)
	}
}
func main(){



//by this method they do not know each other
// go Boring("boring!")
// fmt.Println("I'm listening")
// time.Sleep(2*time.Second)
// fmt.Println("You're boring; I'm leaving")

//by using channel they know each other and data where it coming from

c:=make(chan string)

go boring("im boring",c)

for i:=0;i<5;i++{
	fmt.Printf("you say; %q\n",<-c)
}

fmt.Println("You're boring; I'm leaving")
}


//using unbuffered channel we can achieve the syncronisation and communication between the go routines
//buffered channel removes the synchronisation

