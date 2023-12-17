# Part A - OpenMP Programs

1. Write a program to sort an array on n elements using both sequential and parallel merge sort(using Section). Record the difference in execution time.

2. Estimate the value of pi using:

    $$4\sum_{k=0}^{\infty} \frac{(-1)^k}{2k + 1}$$
    Parallelize the code by removing loop carried dependency and record both serial and parallel execution times.
    (Implemented using [Monte Carlo Method - Refer Page 18](https://www.openmp.org/wp-content/uploads/omp-hands-on-SC08.pdf))

3. Write an OpenMP program that divides the Iterations into chunks containing 2 iterations, respectively (OMP_SCHEDULE=static,2). Its input should be the number of iterations, and its output should be which iterations of a parallelized for loop are executed by which thread. For example, if there are two threads and four iterations, the output might be the following:
    
    a.	Thread 0 : Iterations 0 −− 1
    
    b.	Thread 1 : Iterations 2 −− 3

4.	Write a program to calculate n Fibonacci numbers using Parallel Directive. Demonstrate elimination of the race condition using Schedule directive.

5.	Write a program to find the prime numbers from 1 to n employing parallel for directive. Record both serial and parallel execution times.

6.	Parallel Vector Addition

7.	Write a program   calculate the sum of first 100 Numbers. (Using critical directive)

# Part B - MPI

1. Write an MPI program to demonstrate MPI_Send and MPI_Recv.

2. Write an MPI program to demonstrate deadlock using point to point communication.

3. Write an MPI program to avoid deadlock by altering the call sequence.

4. Write an MPI program to demonstrate avoidance of deadlock by non-blocking calls.

5. Write an MPI program to demonstrate avoidance of deadlock by using MPI_Sendrecv.

6. Write an MPI program to demonstrate the synchronization between two phases of program.

7. Write an MPI program to demonstrate Broadcast operation.

8. Write an MPI program to demonstrate MPI_Gather.

9. Write an MPI program to demonstrate to MPI_Scatter.

10. Write an MPI program to demonstrate to demonstrate MPI_Scatter and MPI_Gather.

11. Write an MPI program to demonstrate MPI_Reduce(MPI_MAX, MPI_MIN, MPI_SUM, MPI_PROD).

12. Write an MPI program to demonstrate MPI_Allreduce (MPI_MAX, MPI_MIN, MPI_SUM, MPI_PROD).
