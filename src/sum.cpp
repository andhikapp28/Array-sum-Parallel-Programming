#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define n 16

int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
int a2[1000];

int main(int argc, char* argv[]){
 int ID, np, proses,hasil, sum=0;
 double t1, t2; 
 
 MPI_Status status;
 MPI_Init(&argc, &argv);
 
 t1 = MPI_Wtime();
 
 MPI_Comm_rank(MPI_COMM_WORLD, &ID);
 MPI_Comm_size(MPI_COMM_WORLD, &np);
 
 if (ID == 0) {
	int index, i;
	proses = n / np;
		if (np > 1) {
			for (i = 1; i < np - 1; i++) {
				index = i * proses;
				MPI_Send(&proses,1, MPI_INT, i, 0, MPI_COMM_WORLD);
				MPI_Send(&a[index],proses,MPI_INT, i, 0,MPI_COMM_WORLD);
			}
			index = i * proses;
			int sisa = n - index;
			MPI_Send(&sisa,1, MPI_INT,i, 0,	MPI_COMM_WORLD);
			MPI_Send(&a[index],sisa,MPI_INT, i, 0,MPI_COMM_WORLD);
		}
		for (i = 0; i < proses; i++)
			sum += a[i];
		int tmp;
		for (i = 1; i < np; i++) {
			MPI_Recv(&tmp, 1, MPI_INT,MPI_ANY_SOURCE, 0,MPI_COMM_WORLD,	&status);
			int sender = status.MPI_SOURCE;
			sum += tmp;
		printf("Hasil Sementara : %d\n", sum);
		}
		t2 = MPI_Wtime(); 
		printf("Total : %d\n", sum);
		printf( "Elapsed time is %f\n", t2 - t1 );
	}else{

		MPI_Recv(&hasil,1, MPI_INT, 0, 0,MPI_COMM_WORLD,&status);
		MPI_Recv(&a2, hasil,MPI_INT, 0, 0,MPI_COMM_WORLD,&status);

		int partial_sum = 0;
		for (int i = 0; i < hasil; i++)
			partial_sum += a2[i];
		MPI_Send(&partial_sum, 1, MPI_INT,0, 0, MPI_COMM_WORLD);	
		printf("Kirim Hasil : %d\n", partial_sum);
	}
	MPI_Finalize();
	return 0;
}
