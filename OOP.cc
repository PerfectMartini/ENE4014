class Expr {
public:
    virtual int eval() = 0;
};

class Constant : public Expr {
public:
    int val;
    Constant(int v) : val(v) {}
    Constant(const Constant& c) : val(c.val) {}
    int eval() override {
        return val;
    }
};

class Negate : public Expr {
public:
    Expr& e2;
    Negate(Expr& _e2) : e2(_e2) {}
    Negate(const Negate& n) : e2(n.e2) {}
    int eval() override {
        return ~(e2.eval());
    }
};

class Add : public Expr {
public:
    Expr& e1;
    Expr& e2;
    Add(Expr& _e1, Expr& _e2) : e1(_e1), e2(_e2) {}
    Add(const Add& a) : e1(a.e1), e2(a.e2) {}

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