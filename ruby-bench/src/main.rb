require 'benchmark'

require_relative 'test_data'

NUM_VECS = 100
VEC_LENGTH = 20000

def calculate_direct_indexed(va, vb)
  sum = 0

  for i in 0..va.length - 1
    entry = va[i]

    sum += entry * vb[i] if entry > 2
  end

  sum
end

def calculate_direct(va, vb)
  sum = 0

  va.each_with_index do |entry_a, index|
    sum += entry_a * vb[index] if entry_a > 2
  end

  sum
end

def calculate_iter(va, vb)
  va.zip(vb)
    .select { |entry_a, _| entry_a > 2 }
    .map { |entry_a, entry_b| entry_a * entry_b }
    .sum
end

test_data = TestData.new(NUM_VECS, VEC_LENGTH)

Benchmark.bm do |benchmark|
  va = test_data.sample
  vb = test_data.sample

  # Warmup
  20.times { calculate_iter(test_data.sample, test_data.sample) }

  benchmark.report('Iterator') do
    calculate_iter(va, vb)
  end

  # Warmup
  20.times { calculate_direct(test_data.sample, test_data.sample) }
  
  benchmark.report('Direct') do
    calculate_direct(va, vb)
  end

  # Warmup
  20.times { calculate_direct_indexed(test_data.sample, test_data.sample) }

  benchmark.report('Direct indexed') do
    calculate_direct_indexed(va, vb)
  end
end
