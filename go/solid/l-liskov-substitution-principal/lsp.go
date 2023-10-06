package main

import "fmt"

//Let's consider a struct Animal:

type Animal struct{
	Name string
}

func(a Animal)makeSound(){
	fmt.Println("animal sound")
}

// Now, let's say we want to create a new struct Bird that represents a specific type of animal:

type Bird struct{
	Animal
}

func(b Bird)makeSound(){
	fmt.Println("chirp chirp")
}

// This principle states that objects of a superclass should be replaceable with objects of a subclass without affecting the correctness of the program.
//  This helps to ensure that the relationships between classes are well-defined and maintainable.

type AnimalBehaviour interface{
	makeSound()
}

func makeSound(ab AnimalBehaviour){
 ab.makeSound()
}

func main(){
	a:=Animal{}
	b:=Bird{}
	makeSound(a)
	makeSound(b)
}

