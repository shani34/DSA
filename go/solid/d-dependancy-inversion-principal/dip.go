package main

import "fmt"

//this states that high-level module should not dependent on low-level module.
//But rather should depend on abstruction.
//This helps rather to reduce the coupling between components
//Suppose we have a struct Worker that represents a worker in a company,
//  and a struct Supervisor that represents a supervisor:

type worker struct{
	id int
	name string
}

func(w worker)GetId()int{
	return w.id
}

func(w worker)GetName()string{
	return w.name
}

type supervisor struct{
	id int
	name string
}


func(w supervisor)GetId()int{
	return w.id
}

func(w supervisor)GetName()string{
	return w.name
}

//Now, for the anti-pattern, let's say we have a high-level module Department that represents a department in a company,
//  and needs to store information about the workers and supervisors, which are considered a low-level modules:


// type Department struct{
// 	worker []worker
// 	supervisor []supervisor
// }

//Note: the above piece of code is dependent on low level module

//According to the Dependency Inversion Principle, high-level modules should not depend on low-level modules. Instead, both should depend on abstractions.
// To fix my anti-pattern example, I can create an interface Employee that represents both, worker and supervisor:

type Employee interface{
	GetId()int
	GetName()string
}

//Now I can update the Department struct so it no longer depends on low-level modules:

type Department struct{
	Employee []Employee
}

func(d *Department)AddEmployee(e Employee){
	d.Employee=append(d.Employee, e)
}

func(d *Department)getEmployeeNames()(res []string){
	for _,e:=range d.Employee{
		res = append(res, e.GetName())
	}
	return 
}

func main(){
	d:=Department{}
	d.AddEmployee(worker{id:1,name: "shani"})
	d.AddEmployee(supervisor{id:1,name: "sk"})

	fmt.Println(d.getEmployeeNames())
}

