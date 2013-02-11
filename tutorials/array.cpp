#include <cstdio>
#include <cstdlib>
#include <ctime>

const int min_length = 1024;
const int max_length = 262144;
const int num_loops = 10000;
const int num_insdel = 1000;

int main(int argc, char *argv[]) {

  // loop over lengths
  for (int length = min_length; length <= max_length; length *= 2) {
    printf("length=%6d\n", length);

    // create array of given length
    float *thearray = static_cast<float*>(malloc(length*sizeof(float)));
    for (int i = 0; i < length; ++i)
      thearray[i] = drand48();

    { // loop
      clock_t before = clock();
      float sum = 0.0;
      for (int i = 0; i < num_loops; ++i) {
        for (int j = 0; j < length; ++j)
          sum += thearray[j];
      }
      clock_t after = clock();
      double elapsed = (after-before)/static_cast<double>(CLOCKS_PER_SEC*num_loops*length);
      printf("\tloop_time=%le\n", elapsed);
    }
    
    { // randomly delete and insert elements
      clock_t before = clock();
      for (int i = 0; i < num_insdel; ++i) {
        { // randomly delete element
          // choose random element
          int r = static_cast<int>(drand48()*(length-1));
          // shift elements above
          for (int j = r+1; j < length; ++j)
            thearray[j-1] = thearray[j];
          // realloc array
          thearray = static_cast<float*>(realloc(thearray, (length-1)*sizeof(float)));
        }
        
        { // randomly insert element
          // choose random element
          int r = static_cast<int>(drand48()*(length-1));
          // shift element up
          // realloc array
          thearray = static_cast<float*>(realloc(thearray, length*sizeof(float)));
          for (int j = length-1; j > r; --j)
            thearray[j] = thearray[j-1];
          thearray[r] = drand48();
        }
      }
      clock_t after = clock();
      double elapsed = (after-before)/static_cast<double>(CLOCKS_PER_SEC*num_insdel);
      printf("\tinsdel_time=%le\n", elapsed);
    }

    { // loop over array
      clock_t before = clock();
      float sum = 0.0;
      for (int i = 0; i < num_loops; ++i) {
        for (int j = 0; j < length; ++j)
          sum += thearray[j];
      }
      clock_t after = clock();
      double elapsed = (after-before)/static_cast<double>(CLOCKS_PER_SEC*num_loops*length);
      printf("\tloop_time=%le\n", elapsed);
    }

    // destroy list
    free(thearray);
  }
}
