# Project name
project(DT063G CXX)

# Minimum required cmake version
cmake_minimum_required(VERSION 3.2)

# Compile with c++ 14 support
set(CMAKE_CXX_STANDARD 14)

# Static inclusion of dependencies required for the executables to be independent
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

# Including environmental variable
include_directories($ENV{TOOLS_INCLUDE})



# Save name of directories in variables for reuse
set(LAB_1 "Laboration_1")
set(LAB_2 "Laboration_2")
set(LAB_3 "Laboration_3")
set(LAB_4 "Laboration_4")
set(LAB_5 "Laboration_5")
set(LAB_6 "Laboration_6")
set(LAB_7 "Laboration_7")
set(LAB_8 "Laboration_8")


# Add source directories for laborations
aux_source_directory(${LAB_1}/src LABORATION_1)
aux_source_directory(${LAB_2}/src LABORATION_2)
aux_source_directory(${LAB_3}/src LABORATION_3)
aux_source_directory(${LAB_4}/src LABORATION_4)
aux_source_directory(${LAB_5}/src LABORATION_5)
aux_source_directory(${LAB_6}/src LABORATION_6)
aux_source_directory(${LAB_7}/src LABORATION_7)
aux_source_directory(${LAB_8}/src LABORATION_8)

# Include additional files, important for respective assignment
aux_source_directory(_CodeBase/Bakery LABORATION_2)
aux_source_directory(_CodeBase/PowerSource/src LABORATION_3)
aux_source_directory(_CodeBase/Hanoi/src LABORATION_5)

# Add executables for all configurations!
add_executable(${PROJECT_NAME}_${LAB_1} ${LABORATION_1})
add_executable(${PROJECT_NAME}_${LAB_2} ${LABORATION_2})
add_executable(${PROJECT_NAME}_${LAB_3} ${LABORATION_3})
add_executable(${PROJECT_NAME}_${LAB_4} ${LABORATION_4})
add_executable(${PROJECT_NAME}_${LAB_5} ${LABORATION_5})
add_executable(${PROJECT_NAME}_${LAB_6} ${LABORATION_6})
add_executable(${PROJECT_NAME}_${LAB_7} ${LABORATION_7})
add_executable(${PROJECT_NAME}_${LAB_8} ${LABORATION_8})


# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directories to respective run configuration
target_include_directories(${PROJECT_NAME}_${LAB_1} PRIVATE "./${LAB_1}/include")
target_include_directories(${PROJECT_NAME}_${LAB_2} PRIVATE "./${LAB_2}/include" "_CodeBase/Bakery")
target_include_directories(${PROJECT_NAME}_${LAB_3} PRIVATE "./${LAB_3}/include" "./_CodeBase/PowerSource/include")
target_include_directories(${PROJECT_NAME}_${LAB_4} PRIVATE "./${LAB_4}/include")
target_include_directories(${PROJECT_NAME}_${LAB_5} PRIVATE "./${LAB_5}/include" "./_CodeBase/Hanoi/include")
target_include_directories(${PROJECT_NAME}_${LAB_6} PRIVATE "./${LAB_6}/include")
target_include_directories(${PROJECT_NAME}_${LAB_7} PRIVATE "./${LAB_7}/include")
target_include_directories(${PROJECT_NAME}_${LAB_8} PRIVATE "./${LAB_8}/include")