//============================================================================
// Name        : SortSearch.hpp
// Author      : Carlos Gomes
// Version     :
// Copyright   : Copyright Carlos Gomes
// Description : Classes providing the methods for sorting and search vectors.
//============================================================================
#pragma once

#include <random>
#include <assert.h>
#include <limits>

namespace sorting_and_searching {

class Obtain {
public:


	/*!
	 * Creates a vector with a certain size, fills it with random values within a
	 * range and returns it.
	 * @param vector_size is the size of the vector, which should be returned.
	 * @param range is the max and min value of the vector, it ranges from -range to +range.
	 * @return Returns the vector.
	 */
	std::vector<int> getVector(std::size_t vector_size, std::size_t range) {
		assert(vector_size > 0);
		assert(range > 0);
		assert(vector_size < std::numeric_limits<int>::max());
		assert(range < std::numeric_limits<int>::max() );

		std::vector<int> vec(vector_size);
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> uni(-range, range);
		for (auto &v : vec) {
			int random_integer = uni(rng);
			v = random_integer;
		}

		return vec;
	}
};

class Sort {
public:

	/*!
	 * Sorts the values within a given vector in increasing order.
	 * @param v is a vector with integers which should be sorted.
	 */
	void sortVector(std::vector<int> &v) {
		assert(v.size() >= 1u);

		int temp;

		for (std::size_t i = 0u; i < v.size(); ++i) {
			for (std::size_t j = 0u; j < v.size() - 1; ++j) {
				if (v[j] > v[j + 1]) {
					temp = v[j];
					v[j] = v[j + 1];
					v[j + 1] = temp;
				}
			}
		}
	}
};

class Search {
public:
	/*!
	 * Method to search the position of a value inside a vector. If there are
	 * multiple entries with the same value, one entry positions of them is returned.
	 * @param vec is the input vector.
	 * @param X is the value which should be found within the vector.
	 * @return -1 if not found, otherwise the position on the vector.
	 */
	int binary_search(const std::vector<int> &vec, int X) {
		assert(vec.size() >= 1u);
		assert(X < std::numeric_limits<int>::max());


		// Set the begin and end.
		std::size_t itr_begin = 0u;
		std::size_t itr_end = vec.size() - 1;
		while (itr_begin <= itr_end) {
			// Get the iterator in the middle of the search part of the array.
			std::size_t itr = itr_begin + (itr_end - itr_begin) / 2u;

			if (vec[itr] == X) {
				return itr;
			} else if (vec[itr] < X) {
				// Value was not found and
				itr_begin = itr + 1u;
			} else {
				itr_end = itr - 1u;
			}
		} // Iterate until X is found or the search ends.

		// Value was not found, so return -1.
		return -1;
	}
};

}  // namespace sorting_and_searching
