#include <iostream>

#define SINGLETON(x) private: x() = default; friend Singleton<x>;

template <typename T>
class Singleton {
public:
  static T& getInstance() {
    return instance;
  }

  Singleton(Singleton const&) = delete;
  Singleton& operator=(Singleton const&) = delete;
  Singleton(Singleton&&) = delete;
  Singleton& operator=(Singleton&&) = delete;

protected:
  Singleton() = default;
  static T instance;
};
template<typename T>
T Singleton<T>::instance{};

class A: public Singleton<A> {
SINGLETON(A)
public:
   auto test() {
     return "hello";
   }
};

int main() {
  auto& a = A::getInstance();
  // A b{}; // should not be allowed to compile
  // A b; // should not be allowed to compile

  std::cout << a.test() << "\n";
  return 0;
}
