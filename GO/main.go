package main

import (
	"fmt"
	"time"
)

func main() {
	const count = 20000000

	values := make([]uint64, 0, count*2)

	timeNow := time.Now()

	for i := 0; i < count; i++ {
		values = append(values, uint64(i))
	}

	for i := count; i > 0; i-- {
		values = append(values, uint64(i))
	}

	timeExec := time.Since(timeNow)

	ms := timeExec.Seconds() * 1000.0
	fmt.Printf("time exec in milliseconds: %.3f\n", ms)

	antiTrapaca := values[0] + values[len(values)-1]
	_ = antiTrapaca
}
