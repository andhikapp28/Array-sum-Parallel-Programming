# README

## Program Description
This software performs array calculations utilizing Parallel Programming techniques. **MPI (Message Passing Interface)** was chosen as the program's method.

## Installation and Configuration

Please ensure that the following conditions are met before running the program:
1. VirtualBox is already installed on your computer. If not, you can download and install it from the official VirtualBox website.
2. Within VirtualBox, you should have a virtual machine (VM) with an MPI-compatible operating system. For example, Ubuntu already has MPI installed.
3. Ascertain that MPI is installed on the virtual system.

## Executing the Program

To run the software on the virtual machine, follow these steps:
1. Launch the virtual machine's terminal.
2. Paste the program code into the terminal, use another means to move the program file to the virtual computer, or just rewrite the code.
3. Compile the program with the following command (assuming the program has a source file named "sum.cpp"):

   ```bash
   mpicc -o array_parallel sum.cpp
   ```

4. Run the program using the following command:

   ```bash
   mpirun -np <number_of_processes> ./array_parallel
   ```

   Replace `<number_of_processes>` with the desired number of MPI processes you want to use. Make sure the number of processes does not exceed the number of available cores or processors on the virtual machine.

5. The program will start running and perform the array calculation in parallel.

## How to Use

1. After running the program, you may need to input initial data, depending on the program's implementation. The program might provide further instructions in the terminal.
2. The program will process the array calculation in parallel using MPI. Monitor the program's output to see the calculation results.
3. Once the program finishes running, you will obtain the array calculation results processed in parallel.

## Important Notes

- Ensure to configure the virtual machine's resources adequately (e.g., RAM allocation and core/processor settings) to support efficient parallel execution.
- The number of MPI processes used should match the number of available cores or processors. Using too many processes may result in communication overhead and poor performance.

- This program serves as an example, assuming that you have correctly installed MPI on the virtual machine. If there are any issues related to MPI installation, make sure to refer to the appropriate installation guides.

---
