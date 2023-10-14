package main

import(
	"fmt"
	"time"
	"math/rand"
)

func boring(msg string)<-chan string{//returns recieve only channel
	c:=make(chan string)
	
	go func(){//we launch the go routines from inside the function
	  for i:=0; ;i++{
		c<-fmt.Sprintf("%s, %v",msg,i)
		time.Sleep(time.Duration(rand.Intn(1e3))*time.Millisecond)
	  }
	}()
	
	return c
	}
func main(){
	c:=boring("Joe")

	for{
		select{
		case s:=<-c:
			fmt.Println(s)
		case <-time.After(1*time.Second):
			fmt.Println("you are too slow")	
			return
			
		}
	}
}