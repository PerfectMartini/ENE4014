#include <iostream>

class Expr {
public:
    virtual int eval() = 0;
};

class Constant : public Expr {
public:
    int val;
    Constant(int v) : val(v) {}
    int eval() override {
        return val;
    }
};

class Negate : public Expr {
public:
    Expr& e2;
    Negate(Expr& _e2) : e2(_e2) {}
    int eval() override {
        return ~(e2.eval());
    }
};

class Add : public Expr {
public:
    Expr& e1;
    Expr& e2;
    Add(Expr& _e1, Expr& _e2) : e1(_e1), e2(_e2) {}
    int eval() override {
        return (e1.eval() + e2.eval());
    }
};

class Multiply : public Expr {
public:
    Expr& e1;
    Expr& e2;
    Multiply(Expr& _e1, Expr& _e2) : e1(_e1), e2(_e2) {}
    int eval() override {
        return (e1.eval() * e2.eval());
    }
};

void main(void) {
    Constant* c1 = new Constant(5);
    Constant c2(6);
    Add a(*c1, c2);
    std::cout << a.eval() << std::endl;

    c1->val = 7;
    std::cout << a.eval() << std::endl;

    delete c1;
    std::cout << a.eval() << std::endl;

    return;
}