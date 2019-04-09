cmake_minimum_required(VERSION 3.0)

project(modSol)

# find_package(SCIP CONFIG REQUIRED) # add config here
find_package(SCIP )

include_directories(${SCIP_INCLUDE_DIRS})

add_executable(modSol 
    src/cmain.c
)

target_link_libraries(modSol ${SCIP_LIBRARIES} m)  # m for math 

