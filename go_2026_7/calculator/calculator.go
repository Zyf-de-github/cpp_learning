package calculator

import "fmt"


func Calculate[T int|float64](a T, b T, c string)(T) {
	var result T
	switch c {
	case "+":
		result = a + b
	case "-":
		result = a - b
	case "*":
		result = a * b
	case "/":
		if b == 0 {
			fmt.Println("除数不能为0")
			return 0
		}
		result = a / b
	default:
		fmt.Println("不支持的运算符")
		return 0
	}
	fmt.Println(result)
	return result
}