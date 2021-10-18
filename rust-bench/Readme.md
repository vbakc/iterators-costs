# Rust iterators bench

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