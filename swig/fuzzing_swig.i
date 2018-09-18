/* -*- c++ -*- */

#define FUZZING_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "fuzzing_swig_doc.i"

%{
#include "fuzzing/first_block.h"
#include "fuzzing/second_block.h"
%}


%include "fuzzing/first_block.h"
GR_SWIG_BLOCK_MAGIC2(fuzzing, first_block);
%include "fuzzing/second_block.h"
GR_SWIG_BLOCK_MAGIC2(fuzzing, second_block);
