#include <list>
#include <iostream>

template <typename U, typename F, typename T>
std::list<U> fmap(F f, const std::list<T>& xs)
{
    if (xs.empty())
    {
        return std::list<U>();
    }
    else
    {
        std::list<U> ys;
        ys.push_back(f(xs.front()));
        auto rest = xs;
        rest.pop_front();
        ys.splice(ys.end(), fmap<U>(f, rest));
        return ys;
    }
}

int main(void)
{
    // test code
    std::list<int> xs = {1, 2, 3, 4, 5};
    std::list<float> ys = fmap<float>([](int x) { return x / 2.0 ; }, xs);
    for (auto y : ys)
    {
        std::cout << y << std::endl;
    }
    return 0;
}