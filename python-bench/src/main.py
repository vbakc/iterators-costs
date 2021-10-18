import random
import timeit
import statistics

from functools import reduce

class TestSet:
    def __init__(self, num_vectors, vector_length):
        self._vectors = [
            [random.randrange(0, 10) for _ in range(vector_length)] for _ in range(num_vectors)
        ]

    def sample(self):
        return random.sample(self._vectors, 2)

    def get(self, idx):
        return self._vectors[idx]


TEST_SET = TestSet(100, 20_000)


def calculate_direct(la, lb):
    s = 0
    for a, b in zip(la, lb):
        if a > 2:
            s += a * b
    return s


def calculate_iterator(la, lb):
    zipped = zip(la, lb)
    filtered = filter(lambda x: x[0] > 2, zipped)
    mapped = map(lambda x: x[0] * x[1], filtered)
    return sum(mapped)


def bench_calculate_direct():
    return calculate_direct(*TEST_SET.sample())


def bench_calculate_iterator():
    return calculate_iterator(*TEST_SET.sample())


if __name__ == "__main__":
    direct = timeit.Timer(bench_calculate_direct).repeat(200, 1)
    iterator = timeit.Timer(bench_calculate_iterator).repeat(200, 1)

    print(f"Direct loop {statistics.mean(direct) * 1_000_000_000} µsec")
    print(f"Iterator {statistics.mean(iterator) * 1_000_000_000} µsec")
