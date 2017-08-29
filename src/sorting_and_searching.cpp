//============================================================================
// Name        : sorting_and_searching.cpp
// Author      : Carlos Gomes
// Version     :
// Copyright   : Copyright Carlos Gomes
// Description : Sorts a random vector, and searches a random value with
// binary_search inside this vector
//============================================================================

#include <iostream>
#include <vector>

#include "SortSearch.hpp"

int main(int argc, char **argv) {
  std::cout << "Hello World!" << std::endl;

  // Create instances of the classes providing the required methods.
  sorting_and_searching::Obtain obtainer;
  sorting_and_searching::Sort sorter;
  sorting_and_searching::Search searcher;

  // Get a random value, this value is searched later within the vector.
  const std::size_t v_size = 50u;
  const std::size_t range = 100u;
  std::random_device rd;
  std::mt19937 rng(rd());
  std::uniform_int_distribution<int> uni(1, v_size);
  std::size_t random_integer = uni(rng);
  int search_value = uni(rng);

  std::vector<int> v = obtainer.getVector(random_integer, range);

  std::cout << "\nData before sorting: ";
  for (std::size_t j = 0u; j < v.size(); ++j)
    std::cout << v[j] << " ";

  sorter.sortVector(v);

  std::cout << "\nData after sorting: ";
  for (std::size_t j = 0u; j < v.size(); ++j)
    std::cout << v[j] << " ";

  int pos = searcher.binary_search(v, search_value);

  if (pos < 0) {
    std::cout << "\n\n" << search_value << " was *not* found!" << std::endl;
  } else {
    std::cout << "\n\n"
              << search_value << " was found at the " << pos << " position!"
              << std::endl;
  }

  return 0;
}
