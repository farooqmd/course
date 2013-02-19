#include <iostream>
#include <ctime>
#include <functional>
#include <random>
#include <stdexcept>

using namespace std;

const int min_length = 1024;
const int max_length = 262144;
const int num_loops = 10000;
const int num_insdel = 1000000;

// forward declaration
struct Node;

struct Node {
  float data;
  Node *next;
};

typedef Node* List;

int main(int argc, char *argv[]) {
  default_random_engine rng;
  uniform_real_distribution<float> dist;
  auto random = bind(dist, rng);

  // loop over lengths
  for (int length = min_length; length <= max_length; length *= 2) {
    cout << "length=" << length << endl;

    // create list of given length
    List thelist = NULL;
    for (int i = 0; i < length; ++i) {
      List tmplist = thelist;
      thelist = new Node;
      thelist->data = random();
      thelist->next = tmplist;
    }

    clock_t before, after;
    double elapsed;
    float sum;

    // loop over list
    before = clock();
    sum = 0.0;
    for (int i = 0; i < num_loops; ++i) {
      for (List rest = thelist; rest != NULL; rest = rest->next) {
        sum += rest->data;
      }
    }
    after = clock();
    elapsed = (after-before)/(1.0*CLOCKS_PER_SEC*num_loops*length);
    cout << "\tloop_time=" << scientific << elapsed << endl;
    // just to make sure the loop is not optimized out
    if (sum < 0.0) throw logic_error("Loop was optimized out!");
    
    List prev_element = thelist;
    // advance to element in the middle
    for (int j = 0; j < length/2; j++)
      prev_element = prev_element->next;
      
    // delete and insert element in the middle of the list
    before = clock();
    for (int i = 0; i < num_insdel; ++i) {
      // delete element
      List tmp = prev_element->next;
      prev_element->next = tmp->next;
      free(tmp);
        
      // insert random element before
      tmp = new Node;
      tmp->data = random();
      tmp->next = prev_element->next;
      prev_element->next = tmp;
    }
    after = clock();
    elapsed = (after-before)/(1.0*CLOCKS_PER_SEC*num_insdel);
    cout << "\tinsdel_time=" << scientific << elapsed << endl;
    
    // mix up list
    List newlist = NULL;
    List e;
    for (int i = length; i > 1; --i) {
      e = thelist;
      // choose random element
      for (int j = random()*(i-1); j > 1; --j) {
        e = e->next;
      }
      List tmp = e->next;
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
      for (List rest = thelist; rest != NULL; rest = rest->next) {
        sum += rest->data;
      }
    }
    after = clock();
    elapsed = (after-before)/(1.0*CLOCKS_PER_SEC*num_loops*length);
    cout << "\tloop_time=" << scientific << elapsed << endl;
    // just to make sure the loop is not optimized out
    if (sum < 0.0) throw logic_error("Loop was optimized out!");

    // destroy list
    while (thelist != NULL) {
      List tmplist = thelist->next;
      delete(thelist);
      thelist = tmplist;
    }
  }
}
