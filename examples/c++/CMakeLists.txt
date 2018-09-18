add_executable(first_block_demo first_block_demo.cc)
target_link_libraries(first_block_demo 
    gnuradio-runtime 
    gnuradio-blocks 
    gnuradio-pmt
    gnuradio-fuzzing
    boost_system)
    
add_executable(second_block_demo second_block_demo.cc)
target_link_libraries(second_block_demo 
    gnuradio-runtime 
    gnuradio-blocks 
    gnuradio-pmt
    gnuradio-fuzzing
    boost_system)
