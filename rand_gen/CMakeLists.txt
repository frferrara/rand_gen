add_library( rand_gen SHARED rand_gen.cpp )

install( TARGETS rand_gen DESTINATION lib )
install( FILES ${PROJECT_SOURCE_DIR}/rand_gen/rand_gen.hpp DESTINATION include )