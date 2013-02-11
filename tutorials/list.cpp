#include <cstdio>
#include <cstdlib>
#include <ctime>

const int min_length = 1024;
const int max_length = 262144;
const int num_loops = 10000;
const int num_insdel = 1000;

typedef struct _SLnode {
  float data;
  struct _SLnode *next;
} SLnode;

typedef SLnode* SLtype;

int main(int argc, char *argv[]) {

  // loop over lengths
  for (int length = min_length; length <= max_length; length *= 2) {
    printf("length=%6d\n", length);
    // create list of given length
    SLtype thelist = NULL;
    for (int i = 0; i < length; ++i) {
      SLtype tmplist = thelist;
      thelist = static_cast<SLtype>(malloc(sizeof(SLnode)));
      thelist->data = drand48();
      thelist->next = tmplist;
    }

    { // loop over list
      clock_t before = clock();
      float sum = 0.0;
      for (int i = 0; i < num_loops; ++i) {
        for (SLtype rest = thelist; rest != NULL; rest = rest->next) {
          sum += rest->data;
        }
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
          SLtype prev_element = thelist;
          for (int r = static_cast<int>(drand48()*(length-1)); r > 0; r--) 
            prev_element = prev_element->next;
          // delete next element
          SLtype tmp = prev_element->next;
          prev_element->next = tmp->next;
          free(tmp);
        }
        
        { // randomly insert element
          // choose random element
          SLtype prev_element = thelist;
          for (int r = static_cast<int>(drand48()*(length-1)); r > 0; r--) 
            prev_element = prev_element->next;
          // insert random element before
          SLtype tmp = static_cast<SLtype>(malloc(sizeof(SLnode)));
          tmp->data = drand48();
          tmp->next = prev_element->next;
          prev_element->next = tmp;
        }
      }
      clock_t after = clock();
      double elapsed = (after-before)/static_cast<double>(CLOCKS_PER_SEC*num_insdel);
      printf("\tinsdel_time=%le\n", elapsed);
    }

    { // loop over list
      clock_t before = clock();
      float sum = 0.0;
      for (int i = 0; i < num_loops; ++i) {
        for (SLtype rest = thelist; rest != NULL; rest = rest->next) {
          sum += rest->data;
        }
      }
      clock_t after = clock();
      double elapsed = (after-before)/static_cast<double>(CLOCKS_PER_SEC*num_loops*length);
      printf("\tloop_time=%le\n", elapsed);
    }

    // destroy list
    while (thelist != NULL) {
      SLtype tmplist = thelist->next;
      free(thelist);
      thelist = tmplist;
    }
  }
}
