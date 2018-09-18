// Include header files for each block used in flowgraph
#include <gnuradio/top_block.h>
#include <gnuradio/blocks/file_source.h>
#include <gnuradio/blocks/file_sink.h>
#include <pmt/pmt.h>
#include <fuzzing/second_block.h>

using namespace gr;

int main(int argc, char **argv)
{
  // top block
  top_block_sptr tb = make_top_block("second_block_demo");
  
  // blocks
  static fuzzing::second_block::sptr second_block_0 = fuzzing::second_block::make();
  static blocks::file_source::sptr blocks_file_source_0 = blocks::file_source::make(sizeof(char)*1, argv[1], false);
  static blocks::file_sink::sptr blocks_file_sink_0 = blocks::file_sink::make(sizeof(char)*1, argv[2], false);
  
  // define some properties
  blocks_file_source_0->set_begin_tag(pmt::PMT_NIL);
  blocks_file_sink_0->set_unbuffered(false);
  
  tb->connect(blocks_file_source_0, 0, second_block_0, 0);
  tb->connect(second_block_0, 0, blocks_file_sink_0, 0);
  
  tb->run();

  return 0;
}
