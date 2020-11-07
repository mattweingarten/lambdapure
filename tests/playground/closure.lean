set_option trace.compiler.ir.init true

def bar : Nat -> Nat -> Nat
| 0 , y => y
| x , _ => x

def foo (x : Nat) : Nat -> Nat := bar x


def 


unsafe def main : List String → IO UInt32
| _ => pure 0
