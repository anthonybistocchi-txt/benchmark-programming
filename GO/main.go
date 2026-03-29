package main

import (
	"fmt"
	"time"
)

func main() {
	const count = 20000000

	values := make([]uint64, 0, count)

	timeNow := time.Now()

	for i := 0; i < count; i++ {
		values = append(values, uint64(i))
	}

	for i := count; i > 0; i-- {
		values = append(values, uint64(i))
	}

	timeExec := time.Since(timeNow)

	fmt.Printf("time exec in milliseconds: %.3f\n", float64(timeExec.Nanoseconds())/1000000.0)
}
