// Include header files for each block used in flowgraph
#include <gnuradio/top_block.h>
#include <gnuradio/blocks/file_source.h>
#include <gnuradio/blocks/tagged_stream_to_pdu.h>
#include <gnuradio/uhd/usrp_sink.h>
#include <pmt/pmt.h>

//usage: uhd_app file_in
  
using namespace gr;

int main(int argc, char **argv)
{
  double samp_rate = 32000.;

  // top block
  top_block_sptr tb = make_top_block("uhd_app");
  
  // define blocks  
  static gr::uhd::usrp_sink::sptr uhd_usrp_sink_0 = gr::uhd::usrp_sink::make(::uhd::device_addr_t("192.168.1.40"),
    //::uhd::io_type_t{5},
    ::uhd::stream_args_t("", ""),
    ""
  );
  static blocks::tagged_stream_to_pdu::sptr blocks_tagged_stream_to_pdu_0 = blocks::tagged_stream_to_pdu::make(blocks::pdu::complex_t, "packet_len");
  static blocks::file_source::sptr blocks_file_source_1 = blocks::file_source::make(sizeof(gr_complex)*1, argv[1], false);
  static blocks::file_source::sptr blocks_file_source_0 = blocks::file_source::make(sizeof(gr_complex)*1, "/dev/urandom", true);
  
  // set some properties
  uhd_usrp_sink_0->set_samp_rate(samp_rate);
  uhd_usrp_sink_0->set_center_freq(0, 0);
  uhd_usrp_sink_0->set_gain(0, 0);
  blocks_file_source_0->set_begin_tag(pmt::PMT_NIL);
  blocks_file_source_1->set_begin_tag(pmt::PMT_NIL);        
  
  tb->connect(blocks_file_source_1, 0, blocks_tagged_stream_to_pdu_0, 0);
  tb->msg_connect(blocks_tagged_stream_to_pdu_0, "pdus", uhd_usrp_sink_0, "command");
  tb->connect(blocks_file_source_0, 0, uhd_usrp_sink_0, 0);

  tb->run();

  return 0;
}











