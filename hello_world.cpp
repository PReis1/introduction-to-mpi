#include <iostream>
#include <mpi.h>

int main(int argc, char** argv) {
  // Initialisation
  int MPI_Init(int *argc, char ***argv);

  // Reading size and rank
  int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  // Printing
  std::cout << "Hello world, from process #" << rank << std::endl;
  
  // Finalisation
  int MPI_Finalize();

  return 0;
}