cmake_minimum_required(VERSION 3.0)

project(Roptimization)

find_package(SCIP CONFIG REQUIRED) # add config here

include_directories(${SCIP_INCLUDE_DIRS})

add_executable(reoptimization
    src/cmain.c
)

target_link_libraries(reoptimization  ${SCIP_LIBRARIES} m)  # m for math 

