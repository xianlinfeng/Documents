% this model will solve the problem with warm start

include "globals.mzn";

int: n; % Number of nodes
int: e; % Number of edges

array[1..n] of opt int: solution;
array[1..n] of var 1..n-1: c;   % Color of node n
array[1..e,1..2] of 1..n: E; % 2d array, rows = edges, 2 cols = nodes per edge

constraint forall(i in 1..e)(c[E[i,1]] != c[E[i,2]] ); % Two linked nodes have diff color
constraint c[1] = 1; % Break Symmetry, force fist color == 0

% Big symmetry breaker. A new color J is only allowed to appear after colors 0..J-1 have been seen before (in any order)
constraint forall(i in 1..n-1)( value_precede(i,i+1, c));

% float: alpha;
% var int: distance = sum (v in 1..n where occurs(solution[v])) (c[v] != deopt(solution[v]));

var float: obj = max(c);


solve ::warm_start([c[v] | v in 1..n where occurs(solution[v])],[deopt(solution[v]) | v in 1..n where occurs(solution[v])]) minimize obj ;
% solve minimize obj ;

output [show(c),"\nmax(c) =",show(max(c))];
