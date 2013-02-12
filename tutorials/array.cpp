#include <cstdio>
#include <cstdlib>
#include <ctime>

const int min_length = 1024;
const int max_length = 262144;
const int num_loops = 10000;
const int num_insdel = 10000;

int main(int argc, char *argv[]) {

  // loop over lengths
  for (int length = min_length; length <= max_length; length *= 2) {
    printf("length=%6d\n", length);

    // create array of given length
    float *thearray = static_cast<float*>(malloc(length*sizeof(float)));
    for (int i = 0; i < length; ++i)
      thearray[i] = drand48();

    clock_t before, after;
    double elapsed;

    // loop
    before = clock();
    float sum = 0.0;
    for (int i = 0; i < num_loops; ++i) {
      for (int j = 0; j < length; ++j)
        sum += thearray[j];
    }
    after = clock();
    elapsed = (after-before)/(1.0*CLOCKS_PER_SEC*num_loops*length);
    printf("\tloop_time=%le\n", elapsed);
    // just to make sure the loop is not optimized out
    if (sum < 0.0) printf("Error!\n");
    
    // delete and insert elements
    // choose element
    int idx = length/2;

    before = clock();
    for (int i = 0; i < num_insdel; ++i) {
      // delete element
      // shift elements up
      for (int j = idx+1; j < length; ++j)
        thearray[j-1] = thearray[j];
      // realloc array
      thearray = static_cast<float*>(realloc(thearray, (length-1)*sizeof(float)));
      
      // insert element
      // realloc array
      thearray = static_cast<float*>(realloc(thearray, length*sizeof(float)));
      // shift elements down 
      for (int j = length-1; j > idx; --j)
        thearray[j] = thearray[j-1];
      thearray[idx-1] = drand48();
    }
    after = clock();
    elapsed = (after-before)/(1.0*CLOCKS_PER_SEC*num_insdel);
    printf("\tinsdel_time=%le\n", elapsed);
  
    // destroy array
    free(thearray);
  }
}
