# C# iterators (LINQ) bench

## Results

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
