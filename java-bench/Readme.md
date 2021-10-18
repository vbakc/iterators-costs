# Java iterator bench

## Results

```
# JMH version: 1.27
# VM version: JDK 11.0.12, OpenJDK 64-Bit Server VM, 11.0.12+5-void-r2
# VM invoker: /usr/lib/jvm/openjdk11/bin/java
# VM options: <none>
# JMH blackhole mode: full blackhole + dont-inline hint
```

```
Benchmark                                   Mode  Cnt        Score       Error  Units
FunctionsBenchmark.benchmarkBaselineSelect  avgt    5       15.602 ±     0.072  ns/op
FunctionsBenchmark.benchmarkDirect          avgt    5    49209.334 ±   705.441  ns/op
FunctionsBenchmark.benchmarkIterator        avgt    5   256662.805 ±  1047.067  ns/op
FunctionsBenchmark.benchmarkIteratorGuava   avgt    5  1027566.793 ± 67169.364  ns/op
```