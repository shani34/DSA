package main

import "fmt"

//This principal states that struct should be open for extention and closed for modification
//meaning that behavior of struct should be extended without modifying it

// Let’s say I have a task to build a payment system that will be able to process credit card payments.
// It should also be flexible enough to accept different types of payment methods in future.

type PaymentMethod interface{
	Pay()
}

type Payment struct{}

func(p Payment)Process(pm PaymentMethod){
	pm.Pay()
}

type CreditCard struct{
	amount float64
}

func(cc CreditCard)Pay(){
	fmt.Println("Paid using CreditCard:",cc.amount)
}

func main(){
	p:=Payment{}
	cc:=CreditCard{12.45}
	p.Process(cc)
	//adding a new payment method 
	pp:=Paypal{45}
	p.Process(pp)
}

//as per OCP payment struct should be open for extendable but closed for modification
//adding a new payment method should be like this

type Paypal struct{
	amount float64
}

func(pp Paypal)Pay(){
	fmt.Println("amount paid using paypal:",pp.amount)
}

