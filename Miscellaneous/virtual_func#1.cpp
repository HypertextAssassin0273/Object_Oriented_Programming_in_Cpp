#include <iostream>
using namespace std;

class A {
 public:
  virtual void f() = 0;
};

class B: public A {
 private:
  virtual void f() {
    cout << "B::f()" << endl;
  }
};

class C: public B {
 protected:
  virtual void f() {
   cout << "C::f()" << endl;
  }
};

int main() {
  B *b = new B();
  // This is NOT legal:
  //   b->f();
  C *c = new C; // alternate: C -> C()
  // Nor is this:
  //   c->f();

  // Why is this legal?
  A *a1 = b;
  a1->f();  // Prints "B::f()"
  A *a2 = c;
  a2->f();  // Prints "C::f()"

  return 0;
}
