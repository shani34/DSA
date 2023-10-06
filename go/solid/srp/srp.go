package main

//single responsibility prinicpal states that a struct should have only one reason to change 
//meaning the struct should have only one responsibility
//lets say we are having the employee struct 

type Employee struct{
	Name string
	Salary float64
	Address string
}

// according to the srp we can separate the above info into the two
// struct one is employeeInfo and other is employeeAddress

type EmployeeInfo struct{
	Name string
	Salary float64
}

type EmployeeAddress struct{
	Address string
}

func(e *EmployeeInfo)GetSalary()float64{
	return e.Salary
}

func(ea *EmployeeAddress)GetAddress()string{
	return ea.Address
}

//makes easy to maintainable code and also readable
