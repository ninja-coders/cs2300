-module(my_lists).
-export([delete/2, insert/2, head/1, tail/1]).

head([]) -> [];
head([H|_]) -> H.

tail([]) -> [];
tail([_|T]) -> T.

delete(_,[]) -> [];
delete(X,[X|T]) -> T;
delete(X,[H|T]) -> [H|delete(X,T)].

insert(X,[]) -> [X];
insert(X,L) -> [X|L].

