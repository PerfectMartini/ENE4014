#include <iostream>
#include <cassert>
#include <memory>


template<class T>
class List
{
private:
  struct Node
  {
    T _val;
    std::shared_ptr<const Node> _next;
    Node(T v, std::shared_ptr<const Node> next): _val(v), _next(next) {}
  }; // Node
  std::shared_ptr<const Node> _head;
  List(std::shared_ptr<const Node> head): _head(head) {
  }
  
public:
  List() {}
  List(T v, List const& tail): 
    _head(std::make_shared<Node>(v, tail._head)) {}

  template<typename ...Args>
  List(Args... args) {
    auto reverse_list = [](auto&& ...args) {
      List<T> list;
      (void)std::initializer_list<int>{((list = list.cons(args)), 0)...};
      return list;
    };
    *this = reverse_list(args...).reverse();
  }
    
  bool isEmpty() const { return !_head; }

  T head() {
    assert(!isEmpty());
    return _head->_val;
  }
  List tail() {
    assert(!isEmpty());
    return List(_head->_next);
  }
  List cons(T v) {
    return List(v, *this);
  }
  List reverse() {
    List<T> list;
    for (auto x = *this; !x.isEmpty(); x = x.tail()) {
      list = list.cons(x.head());
    }
    return list;
  }

}; // List

int main()
{
    List<int> l{1, 2, 3};
    std::cout << "head: " << l.head() << std::endl;
    return 0;
}
