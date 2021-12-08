# A look at clang and optimization techniques

## Introduction
<p>
I recently wrote a small C-program to do some benchmarking and
when examining the resulting assembler code I was surprised to
see the applied program transformations.  Here I will report my
findings.
</p>
You are perhaps already familiar with the famous Fibonacci sequence
<pre>
    0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
</pre>
The sequence can be defined recursively:
<pre>
    FIB(0) = 0
    FIB(1) = 1
    FIB(n) = FIB(n-1) + FIB(n-2), for n > 2
</pre>
