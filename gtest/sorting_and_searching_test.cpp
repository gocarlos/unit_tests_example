//============================================================================
// Name        : sorting_and_searching_test.cpp
// Author      : Carlos Gomes
// Version     :
// Copyright   : Copyright Carlos Gomes
// Description : Unit test for the function of the classes provided in
// 				 SortSearch.hpp
//============================================================================

#include "gtest/gtest.h"

#include "../include/SortSearch.hpp"

namespace sorting_and_searching {

// Parameters for different tests.
// TODO(gocarlos) implement fuzzing for the unit tests.
const std::size_t vec_size = 50;
const std::size_t range = 100;

TEST(VecGenTest, test_right_generation_length) {

	Obtain obtainer;
	std::vector<int> v = obtainer.getVector(vec_size, range);

	EXPECT_EQ(v.size(), vec_size);
}

TEST(VecGenTest, test_range) {

	Obtain obtainer;
	std::vector<int> vec = obtainer.getVector(vec_size, range);

	int error = 0;
	for (std::size_t i = 0; i < vec.size() - 1; i++) {
		if (std::abs(vec[i]) > range) {
			std::cout << range << std::endl;
			++error;
		}
	}

	EXPECT_EQ(error, 0);
}

TEST(SorterTest, test_right_sorting_length) {

	Obtain obtainer;
	std::vector<int> v = obtainer.getVector(vec_size, range);

	Sort sorter;
	sorter.sortVector(v);

	EXPECT_EQ(v.size(), vec_size);
}

TEST(SorterTest, test_right_order) {

	Obtain obtainer;
	std::vector<int> vec = obtainer.getVector(vec_size, range);

	Sort sorter;
	sorter.sortVector(vec);

	int error = 0;
	for (std::size_t i = 0; i < vec.size() - 1; i++) {
		if (vec[i] > vec[i + 1]) {
			++error;
		}
	}

	EXPECT_EQ(error, 0);
}

TEST(SearchTest, containing_search_value) {

	Obtain obtainer;
	std::vector<int> v = obtainer.getVector(vec_size, range);

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(0, vec_size - 1);
	int random_integer = uni(rng);
	int x = v[random_integer];

	Sort sorter;
	sorter.sortVector(v);

	Search searcher;

	EXPECT_GE(searcher.binary_search(v, x), 0);
}

TEST(SearchTest, not_containing_search_value) {

	Obtain obtainer;
	std::vector<int> v = obtainer.getVector(vec_size, range);

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(range + 1, range * 10);
	int random_integer = uni(rng);

	int x = random_integer;

	Sort sorter;
	sorter.sortVector(v);

	Search searcher;

	EXPECT_LT(searcher.binary_search(v, x), 0);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

}  // namespace sorting_and_searching
