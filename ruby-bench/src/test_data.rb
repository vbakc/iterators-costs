class TestData
  def initialize(num_vecs, vec_length)
    @arr = []
  
    num_vecs.times do
      @arr << Array.new(vec_length) { rand(0..10) }
    end
  end

  def sample
    @arr.sample
  end
end
