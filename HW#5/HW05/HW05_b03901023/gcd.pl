gcd(A,B,G):-
A is 0 -> G is B;
B is 0 -> G is A;
A > 0,
B > 0,
A <  B -> A1 is B - A, B1 is A, gcd(A1,B1,G1), G is G1.
A >= B -> A1 is A - B, B1 is B, gcd(A1,B1,G1), G is G1;
