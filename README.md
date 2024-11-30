# NASM-C 
 
 By: Boris Victoria & Kyle Silva

## Results

### 10 elements
```
Average execution time over 30 runs: 59.70 nanoseconds
```

### 100 elements
```
Average execution time over 30 runs: 182.33 nanoseconds
```

### 1000 elements
```
Average execution time over 30 runs: 1640.40 nanoseconds
```

### 10000 elements
```
Average execution time over 30 runs: 18536.20 nanoseconds
```
We see from the benchmarks above that there is a linear correlation between the number of elements and the execution time. The asymptotic complexity of the program is O(n) which can be confirmed by the linearity of the results. 

### Sample Output Checking
![image](https://github.com/user-attachments/assets/56f0c263-535b-44c8-a923-d577eb4d558d)

## Appendix

### Compiling (Linux)
The following commands needs nasm and gcc.

 Main 
```
nasm -f elf64 accel_unix.asm && gcc -o main.out accel_unix.o main.c 
```
 Main for Benchmarking (Only execution time is printed)
```
nasm -f elf64 accel_unix.asm && gcc -o main_bench.out accel_unix.o main_bench.c 
```
### Running (Linux)
The program uses input redirection to get its inputs. See the format of the input file below.
```
./main_out < input_file.txt
```
```
3
0.0, 62.5, 10.1
60.0, 122.3, 5.5
30.0, 160.7, 7.8
```
### Input Generator
There is also an input generator that can be used to create input files. The file name is set as the number of elements to be generated.

Compile
```
gcc -o gen gen.c
```

### Benchmarking (Linux)
Run the benchmark on a Unix-based operating system by using the following command:
```
./test.sh <input.txt>
```
./test.sh - A bash script that runs the program 30 times then outputs the average execution time.
input.txt - A text file containing a comma-separated list of floats.
