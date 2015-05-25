sroot(X,M,SX):-
M = 1 -> SX is 1;
M > 1,
M1 is M - 1,
sroot(X,M1,SX1),
SX is SX1/2 + X/(2*SX1).
