#include <list>
#include <functional>

int sum_list (std::list<int> xs) {
  if(xs.empty()) {
    return 0;
  } else {
    return xs.front() + 
       sum_list(std::list(++xs.begin(), xs.end()));
  }
} 

int sum_list (std::list<int> xs) {
  std::function<int(std::list<int>::iterator)> sum_aux;
  sum_aux = [&](std::list<int>::iterator it) {
    if (it==xs.end()) {
      return 0;
    } else {
      return *it + sum_aux(++it);
    }
  };
  return sum_aux(xs.begin());
}
