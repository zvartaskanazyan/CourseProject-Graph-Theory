# CourseWork-Graph-Theory
Determine if sequence is graphical and create the corresponding graph.

Used the Havel–Hakimi theorem that says we can test if a sequence is graphical by the following procedure:

1. Sort the sequence in decreasing order.
2. If the first term is k,
      a. remove the first term,
      b. subtract 1 from the k following terms.
3. If a negative number is obtained, stop. Otherwise, repeat from step 1. 
