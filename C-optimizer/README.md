# A look at clang and optimization techniques

## Introduction
<p>
I recently wrote a small C-program to do some benchmarking and
when examining the resulting assembler code I was surprised to
see how <tt>clang</tt> had optimized the code.
Here I will report my findings.
</p>
<p>
You are perhaps already familiar with the famous Fibonacci sequence
</p>
<pre>
    0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
</pre>
The sequence can be defined recursively:
<pre>
    FIB(0) = 0
    FIB(1) = 1
    FIB(n) = FIB(n-1) + FIB(n-2), for n > 2
</pre>
<p>
Here is the C-program which prints the first 20 Fibonacci numbers:
</p>
<img src="fib.c.png" />
<p>
On Mac OS with clang, I then compiled the C-code with <tt>-O3</tt> for
maximum optimization (although <tt>-O2</tt> or <tt>-Os</tt>) do the same).
We will now examine the generated code for the <tt>fib</tt> function.
</p>
<img src="fib-1.png" />
<p>
Here, <tt>r0</tt>, <tt>r8</tt>, <tt>r19</tt>, <tt>r20</tt> corresponds
to registers in the M1 ARM processor.

