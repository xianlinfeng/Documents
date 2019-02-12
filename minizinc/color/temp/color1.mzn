include "globals.mzn";

int: n; % Number of nodes
int: e; % Number of edges
int: maxc = 20; % Domain of colors, limits search space. Ideally maxc == 13! if you can solve it
int: frcd; % HACK Number of colors to force to relax problem!

array[1..e,1..2] of int: E; % 2d array, rows = edges, 2 cols = nodes per edge
array[0..n-1] of var 0..maxc: c;   % Color of node n

constraint forall(i in 1..e)(c[E[i,1]] != c[E[i,2]] ); % Two linked nodes have diff color
constraint c[0] == 0; % Break Symmetry, force fist color == 0

% Big symmetry breaker. A new color J is only allowed to appear after colors
% 0..J-1 have been seen before (in any order)
constraint forall(i in 0..n-2)( value_precede(i,i+1, c)  );

% Ideally solve would minimize(max(c)), but that's too slow, so we accept any good
% enough solution that's less than our heuristic "maxc"
constraint max(c)<=maxc;
solve :: int_search(c, smallest, indomain_min, complete) satisfy;

output [ show(max(c)+1), "\n", show(c)];


