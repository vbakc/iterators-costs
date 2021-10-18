#include <random>
#include <iostream>

#include <benchmark/benchmark.h>

#include "test_set.hpp"

const size_t vec_length = 20'000;
const size_t num_vecs = 100;

static void sample_pair(benchmark::State& state) {
    std::random_device rd;
    std::default_random_engine rng(rd());
    TestSet test_set(vec_length, num_vecs, rng);
    for (auto _ : state) {
        benchmark::DoNotOptimize(test_set.sample_pair(rng));
        
    }
}
BENCHMARK(sample_pair);

static void calculate_direct_index(benchmark::State& state) {
    std::random_device rd;
    std::default_random_engine rng(rd());
    TestSet test_set(vec_length, num_vecs, rng);
    for (auto _ : state) {
        const auto& [a, b] = test_set.sample_pair(rng);
        benchmark::DoNotOptimize(calculate_direct_index(a, b));
    }
}

BENCHMARK(calculate_direct_index);

static void calculate_direct(benchmark::State& state) {
    std::random_device rd;
    std::default_random_engine rng(rd());
    TestSet test_set(vec_length, num_vecs, rng);
    for (auto _ : state) {
        const auto& [a, b] = test_set.sample_pair(rng);
        benchmark::DoNotOptimize(calculate_direct(a, b));
    }
}

BENCHMARK(calculate_direct);

static void calculate_ranges(benchmark::State& state) {
    std::random_device rd;
    std::default_random_engine rng(rd());
    TestSet test_set(vec_length, num_vecs, rng);
    for (auto _ : state) {
        const auto& [a, b] = test_set.sample_pair(rng);
        benchmark::DoNotOptimize(calculate_ranges(a, b));
    }
}

BENCHMARK(calculate_ranges);

static void calculate_tranform_reduce(benchmark::State& state) {
    std::random_device rd;
    std::default_random_engine rng(rd());
    TestSet test_set(vec_length, num_vecs, rng);
    for (auto _ : state) {
        const auto& [a, b] = test_set.sample_pair(rng);
        benchmark::DoNotOptimize(calculate_tranform_reduce(a, b));
    }
}

BENCHMARK(calculate_tranform_reduce);

static void calculate_avx(benchmark::State& state) {
    std::random_device rd;
    std::default_random_engine rng(rd());
    TestSet test_set(vec_length, num_vecs, rng);
    for (auto _ : state) {
        const auto& [a, b] = test_set.sample_pair(rng);
        benchmark::DoNotOptimize(calculate_avx(a, b));
    }
}

BENCHMARK(calculate_avx);

BENCHMARK_MAIN();
