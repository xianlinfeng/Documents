cmake_minimum_required(VERSION 3.0.0)
project(FIRSTIP VERSION 1.1.0)

include(/home/arthur/scip_installation/Release/include)
enable_testing()

add_executable(FIRSTIP src/cmain.c  )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
