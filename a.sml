datatype expr =
  Constant of int
| Negate of expr
| Add of expr * expr
| Multiply of expr * expr;

fun eval e = 
   case e of 
        Constant i      => i
      | Negate e2       => ~ (eval e2)
      | Add(e1,e2)      => (eval e1) + (eval e2)
      | Multiply(e1,e2) => (eval e1) * (eval e2);

val expression1 = Add(Constant 3, Multiply(Constant 2, Constant 4));
val result1 = eval expression1;

val expression2 = Negate (Add (Constant 5, Constant (~3)));
val result2 = eval expression2;

val expression3 = Multiply (Negate (Constant 2), Add (Constant 3, Constant 4));
val result3 = eval expression3;

val expression4 = Negate (Multiply (Constant 2, Constant (~3)));
val result4 = eval expression4;

print("result1 = " ^ Int.toString(result1));
print("result2 = " ^ Int.toString(result2));
print("result3 = " ^ Int.toString(result3));
print("result4 = " ^ Int.toString(result4));