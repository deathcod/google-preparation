## Vector push back constant amortised.

The important word here is "amortized". Amortized analysis is an analysis technique that examines a sequence of n operations. If the whole sequence runs in T(n) time, then each operation in the sequence runs in T(n)/n

. The idea is that while a few operations in the sequence might be costly, they can't happen often enough to weigh down the program. It's important to note that this is different from average case analysis over some input distribution or randomized analysis. Amortized analysis established a worst case bound for the performance of an algorithm irrespective of the inputs. It's most commonly used to analyse data structures, which have a persistent state throughout the program.

One of the most common examples given is the analysis of a stack with a multipop operations that pops k
elements. A naive analysis of multipop would say that in the worst case multipop must take O(n) time since it might have to pop off all the elements of the stack. However, if you look at a sequence of operations, you'll notice that the number of pops can not exceed the number of pushes. Thus over any sequence of n operations the number of pops can't exceed O(n), and so multipop runs in O(1)

amortized time even though occasionally a single call might take more time.

Now how does this relate to C++ vectors? Vectors are implemented with arrays so to increase the size of a vector you must reallocate memory and copy the whole array over. Obviously we wouldn't want to do this very often. So if you perform a push_back operation and the vector needs to allocate more space, it will increase the size by a factor m

. Now this takes more memory, which you may not use in full, but the next few push_back operations all run in constant time.

Now if we do the amortized analysis of the push_back operation (which I found here) we'll find that it runs in constant amortized time. Suppose you have n
items and your multiplication factor is m. Then the number of relocations is roughly logm(n). The ith reallocation will cost proportional to mi, about the size of the current array. Thus the total time for n push back is ∑logm(n)i=1mi≈nmm−1, since it's a geometric series. Divide this by n operations and we get that each operation takes mm−1, a constant. Lastly you have to be careful about choosing your factor m. If it's too close to 1 then this constant gets too large for practical applications, but if m is too large, say 2, then you start wasting a lot of memory. The ideal growth rate varies by application, but I think some implementations use 1.5.