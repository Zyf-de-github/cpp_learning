package test_func

import "fmt"

func TryIota() {
    const (
        a = iota   // 0
        b          // 1
        c          // 2
        d = "ha"   // 独立值，iota += 1
        e          // "ha"，iota += 1
        f = 100    // 独立值，iota += 1
        g          // 100，iota += 1
        h = iota   // 7，恢复使用 iota 值
        i          // 8
    )
    fmt.Printf("a=%d, b=%d, c=%d, d=%s, e=%s, f=%d, g=%d, h=%d, i=%d\n", a, b, c, d, e, f, g, h, i)
}