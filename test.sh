#!/usr/bin/env bash

total_time=0
num_runs=30

for i in $(seq 1 $num_runs); do
    elapsed_time=$(./main_bench.out < "$1" | tail -n 1)
    total_time=$(echo "$total_time + $elapsed_time" | bc -l)
done
average_time=$(echo "$total_time / $num_runs" | bc -l)

echo "Average execution time over $num_runs runs: $average_time nanoseconds"




