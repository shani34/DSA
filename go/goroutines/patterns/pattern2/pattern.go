//Multipexing pattern

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
func FanIn(input1, input2 <-chan string)<-chan string{
  c:=make(chan string)

  go func(){
	for{
	c<-<-input1
	}
  }()
  go func(){
	for{
	c<-<-input2
	}
  }()

  return c
}

func main(){

	c:=FanIn(boring("Ann"),boring("joe"))

	for i:=0;i<10;i++{
		fmt.Println(<-c)
	}

	fmt.Println("you both are boring, I am leaving!")

}


//goroutin1, goroutin2->main->prints