# CMake generated Testfile for 
# Source directory: /home/arthur/Documents/scip/Binpacking/check
# Build directory: /home/arthur/Documents/scip/Binpacking/release/check
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(examples-binpacking-build "/usr/bin/cmake" "--build" "/home/arthur/Documents/scip/Binpacking/release" "--target" "binpacking")
set_tests_properties(examples-binpacking-build PROPERTIES  RESOURCE_LOCK "libscip")
add_test(examples-binpacking-u20_00 "/home/arthur/Documents/scip/Binpacking/release/binpacking" "-f" "/home/arthur/Documents/scip/Binpacking/check/../data/u20_00.bpa" "-o" "9" "9")
set_tests_properties(examples-binpacking-u20_00 PROPERTIES  DEPENDS "examples-binpacking-build" PASS_REGULAR_EXPRESSION "Validation         : Success")
add_test(examples-binpacking-u40_00 "/home/arthur/Documents/scip/Binpacking/release/binpacking" "-f" "/home/arthur/Documents/scip/Binpacking/check/../data/u40_00.bpa" "-o" "17" "17")
set_tests_properties(examples-binpacking-u40_00 PROPERTIES  DEPENDS "examples-binpacking-build" PASS_REGULAR_EXPRESSION "Validation         : Success")
add_test(examples-binpacking-u60_00 "/home/arthur/Documents/scip/Binpacking/release/binpacking" "-f" "/home/arthur/Documents/scip/Binpacking/check/../data/u60_00.bpa" "-o" "27" "27")
set_tests_properties(examples-binpacking-u60_00 PROPERTIES  DEPENDS "examples-binpacking-build" PASS_REGULAR_EXPRESSION "Validation         : Success")
