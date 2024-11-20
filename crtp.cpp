#include <print>

#define SINGLETON(x) \
private:             \
    x() = default;   \
    ~x() = default;  \
    friend Singleton<x>;

template <typename T>
class Singleton {
public:
  static T& getInstance() {
    // intentional leak as per Construct On First Use Idiom
    static auto instance = new T();
    return *instance;
  }

  Singleton(Singleton const&) = delete;
  Singleton& operator=(Singleton const&) = delete;
  Singleton(Singleton&&) = delete;
  Singleton& operator=(Singleton&&) = delete;

protected:
  Singleton() = default;
  // may not need to be virtual if it's never destroyed
  ~Singleton() = default;
};

class A: public Singleton<A> {
SINGLETON(A)
public:
   auto test() {
     return "hello";
   }
};

int main() {
  auto& a = A::getInstance();
  // should not be allowed to compile
  // A b{};
  // A c;
  // delete &a;
  // Singleton<A> *d = &a; delete d;

  std::println("{}", a.test());
  return 0;
}
