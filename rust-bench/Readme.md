# Rust iterators bench

There's often no point in writing a manually-unrolled loop, since Rust's iterators in most cases will be faster than a direct loop.

Sometimes it's worth writing AVX2 code or even inline assembly, but it has to be a really hot path for this to make sense. With Rust, the AVX2 code is only `1.8 times` faster than the iterator, and a lot less maintainable.

Rust is fast for a few reasons, including:

- iterators are monomorphic and statically dispatched with no heap allocation
- the actual iterator code is optimised away
- the Rust compiler and LLVM backend are *very* good at the classic optimisations, and
- it will happily use SIMD instructions automatically

You'll notice you pay for these benefits at compile time -- it takes a while for the compiler to do all this work.

Of course, this is with `target-cpu=native` for Rust to enable AVX2 instructions on my machine. This is enabled in the [.cargo/config](.cargo/config) file.

## Benchmarking library

[criterion](https://github.com/bheisler/criterion.rs)

## Results

```
rng select baseline     time:   [17.813 ns 17.835 ns 17.861 ns]
                        change: [-0.5270% -0.3794% -0.2362%] (p = 0.00 < 0.05)
                        Change within noise threshold.
Found 4 outliers among 100 measurements (4.00%)
  3 (3.00%) high mild
  1 (1.00%) high severe

calculate_direct_index  time:   [22.015 us 22.046 us 22.081 us]
                        change: [-1.0632% -0.7723% -0.5066%] (p = 0.00 < 0.05)
                        Change within noise threshold.
Found 6 outliers among 100 measurements (6.00%)
  3 (3.00%) high mild
  3 (3.00%) high severe

calculate_direct        time:   [21.984 us 22.003 us 22.025 us]
                        change: [-0.8702% -0.7001% -0.5323%] (p = 0.00 < 0.05)
                        Change within noise threshold.
Found 21 outliers among 100 measurements (21.00%)
  1 (1.00%) low mild
  3 (3.00%) high mild
  17 (17.00%) high severe

calculate_iter          time:   [8.8967 us 8.9133 us 8.9319 us]
                        change: [-0.1489% +0.0350% +0.2272%] (p = 0.72 > 0.05)
                        No change in performance detected.
Found 22 outliers among 100 measurements (22.00%)
  14 (14.00%) low mild
  5 (5.00%) high mild
  3 (3.00%) high severe

calculate_fold          time:   [8.7852 us 8.7927 us 8.8015 us]
                        change: [-1.3929% -1.2243% -1.0571%] (p = 0.00 < 0.05)
                        Performance has improved.
Found 12 outliers among 100 measurements (12.00%)
  11 (11.00%) high mild
  1 (1.00%) high severe

calculate_avx           time:   [4.8089 us 4.8135 us 4.8191 us]
                        change: [+9.3678% +10.115% +10.744%] (p = 0.00 < 0.05)
                        Performance has regressed.
Found 11 outliers among 100 measurements (11.00%)
  3 (3.00%) high mild
  8 (8.00%) high severe
```