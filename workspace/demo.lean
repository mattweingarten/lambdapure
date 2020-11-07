set_option trace.compiler.ir.init true

def const := 1

def baz (x : Nat) :=  x

def higherorder (f: Nat -> Nat ) (x: Nat) := f x


def higherorder2 (f: Nat -> Nat -> Nat) (x:Nat) (y:Nat) := f x y
