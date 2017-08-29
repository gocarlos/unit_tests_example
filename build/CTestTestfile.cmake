# CMake generated Testfile for 
# Source directory: /home/gocarlos/git/unit_tests_example
# Build directory: /home/gocarlos/git/unit_tests_example/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test1 "unit_test_example_test")
subdirs("external/gtest")
