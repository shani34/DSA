package main

import ("fmt"
"time"
"math/rand"
)

//Generator:function that returns a channel

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

	c:=boring("joe")
	h:=boring("Ann")
	for i:=0;i<5;i++{
		fmt.Println(<-c,i)
		fmt.Println(<-h,i)
	}

	fmt.Println("im leaving!, you are boring")

}