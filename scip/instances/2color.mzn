% this model will solve the problem from scratch

include "globals.mzn";

int: n; % Number of nodes
int: e; % Number of edges

array[1..e,1..2] of 1..n: E; % 2d array, rows = edges, 2 cols = nodes per edge
array[1..n,1..n-1] of var 0..1: c;   % Color of node n

constraint forall(i in 1..e, j in 1..n-1)(c[E[i,1],j] + c[E[i,2],j] <= 1 ); % Two linked nodes have diff color
constraint c[1] = 1; % Break Symmetry, force fist color == 0
% Big symmetry breaker. A new color J is only allowed to appear after colors 0..J-1 have been seen before (in any order)
constraint forall(i in 1..n-1)( value_precede(i,i+1, c));

var int: obj = max(c);

solve minimize obj;

output [show(obj),"\n",show(c)];
% output [show(c)];
