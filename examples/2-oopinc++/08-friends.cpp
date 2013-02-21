#include <iostream>
using namespace std;

class Hidden;

/* class that makes objects of tiles Hidden, and deletes them as
   well */
class HiddenFactory {
  int count;
public:
  HiddenFactory(): count(0) {}
  Hidden *makeHidden();
  void deleteHidden(Hidden *h);
};

// a class that has no public members, in particular no constructors
class Hidden {
private:
  // private constructor, so cannot be created as is
  Hidden(int _magic = 42): magic(_magic)
  { cout << "made Hidden" << magic << endl; }

  // this should be there, otherwise you can still make a clone
  //Hidden(const Hidden &) {}

  // private destructor, so only friends can destroy us
  ~Hidden() { cout << "destroyed Hidden" << magic << endl; }

  /* common use of friends: allow output operator. */
  friend ostream &operator<<(ostream &, const Hidden &);

  /* but, a whole class can do with us as they like.
     Note that this acts like a forward declaration. */
  friend class HiddenFactory;
  //friend Hidden *HiddenFactory::makeHidden();
  //friend void HiddenFactory::deleteHidden(Hidden *);

  int magic;
};

ostream &operator<<(ostream &o, const Hidden &h)
{
  // here, we could not access "magic" with being a friend
  o << "Hidden" << h.magic << " has nothing to say";
  return o;
}

Hidden *HiddenFactory::makeHidden()
{ return new Hidden(++count); }

void HiddenFactory::deleteHidden(Hidden *h)
{ delete h; }

int main() {
  // doesn't compile, destructor private
  //Hidden hidden;

  // works, using the class factory allowed access Hidden
  {
    HiddenFactory factory;
    Hidden *hidden = factory.makeHidden();
    cout << *hidden << endl;

    // oops! forgot to make copy constructor private!
    Hidden *mistake = new Hidden(*hidden);
    factory.deleteHidden(mistake);

    factory.deleteHidden(hidden);
  }

  return 0;
}
