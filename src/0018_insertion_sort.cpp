#include "test.h"

#include <vector>

namespace
{
  void insertion_sort(int * f, std::size_t n)
  {
    if (n < 2) {
      return;
    }

    for (std::size_t j = 1; j < n; ++j) {
      int key = f[j];
      std::size_t i = j;
      while ((i > 0) && (key < f[i - 1])) {
        f[i] = f[i - 1];
        --i;
      }
      f[i] = key;
    }
  }

  TEST(insertion_sort__simple)
  {
    std::vector<int> data =
    {
      8, 2, 4, 9, 3, 6
    };

    insertion_sort(data.data(), data.size());

    std::vector<int> expected =
    {
      2, 3, 4, 6, 8, 9
    };

    ASSERT_EQ(expected, data);
  }
} // anonymous namespace
