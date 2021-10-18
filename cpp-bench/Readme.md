# C++ iterators bench

C++ results are quite interesting. Direct loop is the fastest in current competition. In fact, it's so fast that the difference between direct loop and AVX2 is only `16%`.
\
However, iterators (ranges) are much slower than in Rust.

## Benchmarking library

[benchmark](https://github.com/google/benchmark)

## Results

```
---------------------------------------------------------------------------
Benchmark                                 Time             CPU   Iterations
---------------------------------------------------------------------------
sample_pair_mean                       14.3 ns         14.3 ns           10
sample_pair_median                     14.3 ns         14.3 ns           10
sample_pair_stddev                    0.054 ns        0.052 ns           10
calculate_direct_index_mean           42133 ns        42082 ns           10
calculate_direct_index_median         42128 ns        42078 ns           10
calculate_direct_index_stddev          69.5 ns         68.9 ns           10
calculate_direct_mean                  4669 ns         4651 ns           10
calculate_direct_median                4669 ns         4651 ns           10
calculate_direct_stddev                9.01 ns         8.85 ns           10
calculate_ranges_mean                 47356 ns        47300 ns           10
calculate_ranges_median               47354 ns        47298 ns           10
calculate_ranges_stddev                33.2 ns         32.8 ns           10
calculate_tranform_reduce_mean        40910 ns        40855 ns           10
calculate_tranform_reduce_median      40904 ns        40847 ns           10
calculate_tranform_reduce_stddev       83.5 ns         82.8 ns           10
calculate_avx_mean                     4004 ns         3988 ns           10
calculate_avx_median                   4000 ns         3985 ns           10
calculate_avx_stddev                   17.0 ns         16.7 ns           10
```

## Dependencies


[`conan`](https://conan.io/)
\
`cmake`
