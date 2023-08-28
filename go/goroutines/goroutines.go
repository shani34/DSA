package main

import (
	"fmt"
	"sync"
	
)



func Hello(in <-chan string)<-chan string{
	str:=make(chan string)
	
	
	go func ()  {
		defer close(str)
		for i:=range in {
			str<-i
		}
		
	}()

	return str
}

var wg sync.WaitGroup
func main(){
 
	input:=[]string{"shani","kumar","hello"}
	in:=make(chan string)
	out:=Hello(in)
	
	wg.Add(1)
	go func(){
		defer wg.Done()
      for  i:=range out{
		fmt.Println(i)
	  }
	}()

	for i:=range input{
		in<-input[i]
	}

	close(in)
	wg.Wait()
}