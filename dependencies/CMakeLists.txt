file(GLOB srcfiles "src/*.c")

include_directories(dependencies/include)

add_library(dependencies STATIC ${srcfiles})