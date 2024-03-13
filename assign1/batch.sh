#!/bin/bash

input_sizes=(64 128 256 512 1024 2048 4096 8192 16384 32768)

for size in "${input_sizes[@]}"
do
    echo "Running programs for input size: $size"
   
    # Run program 1
    echo "Running program 1"
    time ./svmm.c $size $size
   
    # Run program 2
    echo "Running program 2"
    time ./naive.c $size $size
   
    # Run program 3 
    echo "Running program 3"
    time ./naivempi.c $size $size
   
    # Run program 4 
    echo "Running program 4"
    time ./tilingomp.c $size $size
   
    # Run program 5
    echo "Running program 5"
    time ./tilingmpi.c $size $size
   
    echo "---------------------------------------------------"
done
