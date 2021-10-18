# C# iterators (LINQ) bench

There are several implementations in addition to the traditional ones: 
- branchless loop, with a safe-ish branchless/mask function to replace `if (x>2)`, implemented using SSE intrinsics
- unrolled loop (also branchless)
- unsafe, unrolled loop (also branchless) using pointer arithmetic
- unsafe, using AVX2 SIMD intrinsics

C# responds well to all of these classic optimisation techniques, because the JIT compiler doesn't have the spare time available to do this stuff for you.

## Benchmarking library

[BenchmarkDotNet](https://benchmarkdotnet.org/articles/overview.html)

## Results

```
BenchmarkDotNet=v0.12.1, OS=void 
AMD Ryzen 7 2700X, 1 CPU, 16 logical and 8 physical cores
.NET Core SDK=5.0.402
  [Host]     : .NET Core 5.0.11 (CoreCLR 5.0.1121.47308, CoreFX 5.0.1121.47308), X64 RyuJIT
  DefaultJob : .NET Core 5.0.11 (CoreCLR 5.0.1121.47308, CoreFX 5.0.1121.47308), X64 RyuJIT
```

|           Method |          Mean |        Error |       StdDev |
|----------------- |--------------:|-------------:|-------------:|
|           Direct |  50,447.15 ns |   241.823 ns |   226.201 ns |
| DirectBranchless |  19,323.35 ns |    72.072 ns |    67.416 ns |
|   DirectUnrolled |  17,707.76 ns |    25.786 ns |    21.532 ns |
|     DirectUnsafe |  13,440.01 ns |    16.022 ns |    14.987 ns |
|  DirectUnsafeAvx |   4,201.13 ns |    13.718 ns |    10.710 ns |
|         Iterator | 457,886.33 ns | 3,838.158 ns | 3,205.036 ns |
|  IteratorSimpler | 464,802.21 ns |   233.169 ns |   206.698 ns |
|   SelectBaseline |      25.48 ns |     0.146 ns |     0.129 ns |

##
