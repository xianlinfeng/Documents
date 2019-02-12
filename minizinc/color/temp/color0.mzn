include "globals.mzn";

int: V;
int: E;

set of int: Verts = 1..V;
set of int: Edges = 1..E;

array [Edges] of Verts: src;
array [Edges] of Verts: dest;

int: Cmax;
set of int: C = 1..Cmax;

array [1..V] of var C: coloring;

constraint forall(e in Edges)(coloring[src[e]] != coloring[dest[e]]);
% constraint value_precede_chain(C,V);

var int: objective = max(v in Verts)(coloring[v]);

solve minimize objective;