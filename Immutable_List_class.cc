/*
 * Immutable_List_class.cc
 * Created on: 2017. 10. 10.
 * Author: 강건
 * E-mail:
 * Github: PerfectMartini
 * Blog:
 * Description: lec02-cpp-fp-2, 21 page
 * Reference: http://www.cplusplus.com/reference
 * XXX: List(T v1, T v2, T v3, … )
 * Vararg인 constructor 구현 가능?
 * (가능하면 구현 부탁)
 */

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
      List<T> list/*  */;
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

int main(void)
{
    List<int> l{1, 2, 3};
    std::cout << l.head() << std::endl;
    std::cout << l.tail().head() << std::endl;
    std::cout << l.tail().tail().head() << std::endl;
    std::cout << l.tail().tail().tail().isEmpty() << std::endl;

  return 0;  
}