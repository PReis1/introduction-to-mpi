#include <iostream>
#include <mpi.h>

struct MPI_Struct {
  int MPI_SOURCE;
  int MPI_TAG;
  int MPI_ERROR;
  int _cancelled;
  size_t _ucount;
};

void probing_process(int &int_sum, float &float_sum) {
  MPI_Status status;
  
  // 1- Probe the incoming message
  MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

  // 2- Get the tag and the source
  int tag = status.MPI_TAG;
  int source = status.MPI_SOURCE;

  // Printing the message
  std::cout << "Received a message from process " << source << " with tag " << tag << std::endl;

  // 3- Add to int_sum or float_sum depending on the tag of the message
  if (tag == 0) {
    int message_int;
    MPI_Recv(&message_int, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
    int_sum += message_int;
  } else if (tag == 1) {
    float message_float;
    MPI_Recv(&message_float, 1, MPI_FLOAT, source, tag, MPI_COMM_WORLD, &status);
    float_sum += message_float;
  }
}
