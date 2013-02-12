#include <cstdio>
#include <cstdlib>
#include <ctime>

const int min_length = 1024;
const int max_length = 262144;
const int num_loops = 10000;
const int num_insdel = 1000000;

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

    clock_t before, after;
    double elapsed;
    float sum;

    // loop over list
    before = clock();
    sum = 0.0;
    for (int i = 0; i < num_loops; ++i) {
      for (SLtype rest = thelist; rest != NULL; rest = rest->next) {
        sum += rest->data;
      }
    }
    after = clock();
    elapsed = (after-before)/(1.0*CLOCKS_PER_SEC*num_loops*length);
    printf("\tloop_time=%le\n", elapsed);
    // just to make sure the loop is not optimized out
    if (sum < 0.0) printf("Error!\n");
    
    SLtype prev_element = thelist;
    // advance to element in the middle
    for (int j = 0; j < length/2; j++)
      prev_element = prev_element->next;
      
    // delete and insert element in the middle of the list
    before = clock();
    for (int i = 0; i < num_insdel; ++i) {
      // delete element
      SLtype tmp = prev_element->next;
      prev_element->next = tmp->next;
      free(tmp);
        
      // insert random element before
      tmp = static_cast<SLtype>(malloc(sizeof(SLnode)));
      tmp->data = drand48();
      tmp->next = prev_element->next;
      prev_element->next = tmp;
    }
    after = clock();
    elapsed = (after-before)/(1.0*CLOCKS_PER_SEC*num_insdel);
    printf("\tinsdel_time=%le\n", elapsed);
    
    // mix up list
    SLtype newlist = NULL;
    SLtype e;
    for (int i = length; i > 1; --i) {
      //      printf("i = %d\n", i);
      e = thelist;
      // choose random element
      for (int j = drand48()*(i-1); j > 1; --j) {
        //        printf("%d\n", j);
        e = e->next;
      }
      SLtype tmp = e->next;
      // remove it
      e->next = e->next->next;
      // and insert it into new list
      tmp->next = newlist;
      newlist = tmp;
    }
    thelist = newlist;

    // loop over list
    before = clock();
    sum = 0.0;
    for (int i = 0; i < num_loops; ++i) {
      for (SLtype rest = thelist; rest != NULL; rest = rest->next) {
        sum += rest->data;
      }
    }
    after = clock();
    elapsed = (after-before)/(1.0*CLOCKS_PER_SEC*num_loops*length);
    printf("\tloop_time=%le\n", elapsed);
    // just to make sure the loop is not optimized out
    if (sum < 0.0) printf("Error!\n");

    // destroy list
    while (thelist != NULL) {
      SLtype tmplist = thelist->next;
      free(thelist);
      thelist = tmplist;
    }
  }
}
