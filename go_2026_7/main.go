package main

import (
    "fmt"
    _ "go_2026_7/test_func"
    "go_2026_7/calculator"
)

func Print() {
   fmt.Println("oooooooooooo")
}

//自动执行的函数，init函数在main函数之前执行
func init() {
   fmt.Println("This is init function")
}

func main() {
   // /* 这是我的第一个简单的程序 */
   // // a := 10
   // fmt.Println("Hello, World!")
   // Print()
   // test_func.AnotherPrint()
   // test_func.PrintGender()
   // a:=2
   // if a<=3{
   //    fmt.Println("a比较大")
   // }
   // test_func.TryIota()
   calculator.Calculate(1, 2, "+")
   calculator.Calculate(1, 2, "-")
   calculator.Calculate(1, 2, "*")
   calculator.Calculate(1, 0, "/")
   calculator.Calculate(1.0, 2, "/")
   calculator.Calculate(1, 2, "1")
}                                            