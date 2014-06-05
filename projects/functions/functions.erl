-module(functions).
-export([make_even/1, sum/1, word_length/1, count/1, average/2, even/1]).

%% This is a map function
make_even([]) -> [];
make_even([H|T]) -> [H*2|make_even(T)].

%% This is a map function
word_length([]) -> [];
word_length([H|T]) -> [length(H)|word_length(T)].

%% This is a Reduce
sum([]) -> 0;
sum([H|T]) -> H + sum(T).

%% This is a Reduce
count([]) -> 0;
count([_|T]) -> 1 + count(T).

%% Simple Equivalence Function
even(X) -> (X rem 2) == 0.

%% Demonstrate using functional composition
average(T,C) -> T / C.


