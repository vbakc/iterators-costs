# Costs of iterators in common programming languages

Please note that it is *not* intended to compare the languages directly. Specifically, I'm not knocking Java or C# here: both are good high-level languages. The benchmarking framework is different for each, so a direct comparison on such a short benchmark is not valuable. What we are demonstrating here is the *relative* cost of using a declarative abstractions vs a simple loop in each language. 

Having said that, Rust does an impressive job of **zero cost abstractions** in certain cases, in much the same way that C++ does (the term is originally from the C++ world). There are always ways to break it, but I've presented this case as an example of where it works really well. I've presented this at work to encourage developers to think about these things:

* How expensive your abstraction is
* Where your hot code is; typically it's only a small part of your code 
  * Consider avoiding doing expensive things on hot code paths
  * If it's a really hot path, consider some aggressive optimisation
* Do benchmarking and profiling if you're not sure what's going on 
* Learn some Rust; it's really fun!

## Benchmarking

It's the following that we're benchmarking: 

- We create a `TestSet` from which we sample pairs of vectors for each iteration.
  - The test set contains 100 vectors
  - Vectors are linear vectors, int32, 20k elements, _pre-initialized_ random values in `[0;10)`
  - Around 8MB dataset to pick vectors from
  - This is all set up before running benchmarks
- Then we have various functions that calculate a number based on a pair of vectors,
  according to these rules for vectors `va` and `vb`:
  - start with `sum = 0`
  - for every pair `a`, `b` in aligned vectors `va`, `vb`
     - if `a > 2`, then `sum += a * b`
  - return `sum`

Pretty simple stuff, but interesting enough to demonstrate some performance characteristics. The `a > 2` is enough to mess up any compiler that decides to use branch instructions, which of course then happens in the Java/C# case. But that's not the focus of this -- we're looking at the cost of iterators primarily.

All benchmarks were run on my AMD Ryzen 2700X system, on Void Linux.

### C#, Java

- Iterators (LINQ or Streams) are very expensive compared to classic loops
  - iterators are in the `(450; 1100) microsecond` range
  - direct loop is around `50 microseconds` in both languages
  - i.e. the simple loop is around `10 to 20 times` faster, so you need to pay attention to where you're using iterators 
- C# and Java classic loops themselves also aren't very fast, and can be improved using the classic techniques:
  - loop unrolling
  - branchless programming
  - SIMD intrinsics (only tested this in C#; I believe Java doesn't support intrinsics just yet)

### Rust

- Rust does an outstanding job with the iterators
  - around 9 microseconds
  - almost as fast as a hand-coded AVX2 implementation
  - iterators are actually faster than simple loops in this case, but they're usually in the same ballpark

### Ruby, Python

- Compared to direct loops, declarative abstractions are not as expensive as in Java and C#
- Predictably, these very high-level languages are much slower (although this is not apples to apples comparison, still those gaps are huge)

## Summary

Times are in **nanoseconds**

| Language | Direct loop | Iterator  | AVX intrinsics |
|----------|------------:|----------:|---------------:|
| Rust     | 22_003      | 8_913     | 4_813          |
| C++      | 4_669       | 47_356    | 4_004          |
| C#       | 50_447      | 457_886   | 4_201          |
| Ruby     | 1_215_000   | 3_373_000 |                |
| Python   | 1_446_320   | 4_308_070 |                |
| Java     | 49_209      | 1_027_566 |                |

## Credits

The [original research](https://github.com/mike-barber/rust-zero-cost-abstractions) including `C#`, `Java` and `Rust` benchmarks belongs to [Michael Barber](https://github.com/mike-barber) and was presented at [Rust Dublin](https://www.youtube.com/watch?v=mX1BsqTfy6E)
