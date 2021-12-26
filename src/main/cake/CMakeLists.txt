add_library(
	cake
	cake.cpp
 "recipe.cpp" "cake_maker.cpp" "cake_carousel.cpp" "command_taker.cpp" "command_panel.cpp")
target_include_directories(cake PUBLIC "${PROJECT_SOURCE_DIR}/include")