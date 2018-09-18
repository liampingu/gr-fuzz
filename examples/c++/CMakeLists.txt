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
    
add_executable(dvbt_app1 dvbt_app1.cc)
target_link_libraries(dvbt_app1 
    gnuradio-runtime 
    gnuradio-filter 
    gnuradio-fft 
    gnuradio-dvbt 
    gnuradio-digital
    gnuradio-blocks 
    gnuradio-pmt
    gnuradio-filter
    boost_system)
    
add_executable(uhd_app1 uhd_app1.cc)
target_link_libraries(uhd_app1 
    gnuradio-runtime 
    gnuradio-blocks 
    gnuradio-pmt
    gnuradio-uhd
    boost_system)
