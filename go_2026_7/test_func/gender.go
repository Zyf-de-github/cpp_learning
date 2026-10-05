package test_func

import "fmt"

// 定义性别枚举
const (
    Unknown = 0
    Female  = 1
    Male    = 2
)

func PrintGender() {
    fmt.Printf("未知=%d, 女性=%d, 男性=%d\n", Unknown, Female, Male)
}