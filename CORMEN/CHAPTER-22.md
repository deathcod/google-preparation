## 22.1-1

Given an adjancency-list representation of a directed graph, how long does it take to compute the out-degree of every vertex? How long does it takes to compute the in-degrees?

## 22.1-2

Give an adjacency-list representation for a complete binary tree on 7 vertices. Give an equivalent adjacency - matrix representation. Assume that vertices are numbered from 1 to 7 as in a binary heap.

## 22.1-3 

The transpose of a directed graph G = (V,E) is the graph G(T) = (V, E(T)), where 
E(T) = {(v,u) belongs to V x V : (u,v) belongs to E}. Thus G(T) is G with all the edges reversed. Describe efficient algorithms for computing G(T) from G, for both the adjancey-list and adjancey-matrix representations of G. Analyse the running times of your algorithm.

## 22.1-5

The square of a directed graph G = (V, E) is the graph G^2 = (V, E^2) such that (u,w) belongs to E*E if and only if for some v belongs to V, both (u,v) belongs to E and (v,w) belongs to E. That is, G*G contains an edge between u and w whenever G contains a path with exactly two edges between u and w. Describe efficent algorithms for computing G*G from G for both the adjanceny-list and adjancency-matrix representations of G. Analyse the running times of your algorithm.

##22.1-7 

The incidence matrix of a directed graph G = (V, E) is a |V| x |E| matrix B = (bij) such that

bij = [ (-1 if edge j leaves vertex i) ,
		(1 if edge j enters vertex i),
		(0 otherwise)]

Describe what the entries of the matrix product BB(T) represent, where B(T) is the transpose of B.