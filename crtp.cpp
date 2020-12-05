#include <iostream>

template <class T>
class Singleton {
public:
  static T& getInstance() {
    return INSTANCE;
  }

  Singleton(Singleton const&) = delete;
  Singleton& operator=(Singleton const&) = delete;
  Singleton(Singleton&&) = delete;
  Singleton& operator=(Singleton&&) = delete;

protected:
  Singleton(){}
  static T INSTANCE;
};
template<typename T>
T Singleton<T>::INSTANCE{};

class A: public Singleton<A> {
public:
   decltype(auto) test() {
     return "hello";
   }
};

int main() {
  auto& a = A::getInstance();
  std::cout << a.test() << "\n";
  return 0;
}
