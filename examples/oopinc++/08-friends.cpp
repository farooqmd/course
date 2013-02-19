#include <iostream>
using namespace std;

class Hidden {
private:
  // private constructor, so cannot be created as is
  Hidden(int _magic = 42): magic(_magic)
  { cout << "made Hidden" << magic << endl; }
  // private destructor, so only friends can destroy us
  ~Hidden() { cout << "destroyed Hidden" << magic << endl; }

  /* common use of friends: allow output operator. */
  friend ostream &operator<<(ostream &, const Hidden &);

  /* but, a whole class can do with us as they like.
     Note that this acts like a forward declaration. */
  friend class HiddenFactory;

  int magic;
};

ostream &operator<<(ostream &o, const Hidden &h)
{
  // here, we could not access "magic" with being a friend
  o << "Hidden" << h.magic << " has nothing to say";
  return o;
}

class HiddenFactory {
  int count;
  // we are a friend, and can have as many Hiddens as we want
  Hidden justSo;
public:
  Hidden *makeHidden() { return new Hidden(++count); }
  void deleteHidden(Hidden *h) { delete h; };
};

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

    factory.deleteHidden(hidden);
    factory.deleteHidden(mistake);
  }

  return 0;
}
