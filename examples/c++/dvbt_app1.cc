// Include header files for each block used in flowgraph
#include <gnuradio/top_block.h>
#include <gnuradio/filter/rational_resampler_base_ccc.h>
#include <gnuradio/filter/rational_resampler_base_fff.h>
#include <gnuradio/fft/fft_vcc.h>
#include <gnuradio/fft/window.h>
#include <dvbt/symbol_inner_interleaver.h>
#include <dvbt/reference_signals.h>
#include <dvbt/reed_solomon_enc.h>
#include <dvbt/inner_coder.h>
#include <dvbt/energy_dispersal.h>
#include <dvbt/dvbt_map.h>
#include <dvbt/convolutional_interleaver.h>
#include <dvbt/bit_inner_interleaver.h>
#include <gnuradio/digital/ofdm_cyclic_prefixer.h>
#include <gnuradio/blocks/multiply_const_vcc.h>
#include <gnuradio/blocks/file_source.h>
#include <gnuradio/blocks/file_sink.h>
#include <pmt/pmt.h>
#include <gnuradio/filter/firdes.h>
#include <gnuradio/blocks/complex_to_float.h>

//usage: dvbt file_in file_out
  
using namespace gr;

int main(int argc, char **argv)
{
  double samp_rate = 32000.;

  // top block
  top_block_sptr tb = make_top_block("dvbt_app");
    
  // define blocks
  
  // self.rational_resampler_xxx_0 = filter.rational_resampler_ccc(interpolation=70, decimation=64, taps=None, fractional_bw=None)
  std::vector<gr_complex> taps;
  taps.push_back(gr_complex(0.1, 0.9));
  taps.push_back(gr_complex(-0.9, 0.1));
  taps.push_back(gr_complex(1.0, 1.5));
  taps.push_back(gr_complex(1.5, -1.0));
  static filter::rational_resampler_base_ccc::sptr rational_resampler_xxx_0 = filter::rational_resampler_base_ccc::make(70, 64, taps);  
  
  // self.fft_vxx_0 = fft.fft_vcc(2048, False, (window.rectangular(2048)), True, 10)
  static fft::fft_vcc::sptr fft_vxx_0 = fft::fft_vcc::make(2048, false, (fft::window::rectangular(2048)), true, 10);
  
  // self.dvbt_symbol_inner_interleaver_0 = dvbt.symbol_inner_interleaver(1512, dvbt.T2k, 1)
  static dvbt::symbol_inner_interleaver::sptr dvbt_symbol_inner_interleaver_0 = dvbt::symbol_inner_interleaver::make(1512, dvbt::T2k, 1);
  
  // self.dvbt_reference_signals_0 = dvbt.reference_signals(gr.sizeof_gr_complex, 1512, 2048, dvbt.QAM16, dvbt.NH, dvbt.C1_2, dvbt.C1_2, dvbt.G1_32, dvbt.T2k, 0, 0)
  static dvbt::reference_signals::sptr dvbt_reference_signals_0 = dvbt::reference_signals::make(sizeof(gr_complex), 1512, 2048, dvbt::QAM16, dvbt::NH, dvbt::C1_2, dvbt::C1_2, dvbt::G1_32, dvbt::T2k, 0, 0);
  
  // self.dvbt_reed_solomon_enc_0 = dvbt.reed_solomon_enc(2, 8, 0x11d, 255, 239, 8, 51, 8)
  static dvbt::reed_solomon_enc::sptr dvbt_reed_solomon_enc_0 = dvbt::reed_solomon_enc::make(2, 8, 0x11d, 255, 239, 8, 51, 8);
  
  // self.dvbt_inner_coder_0 = dvbt.inner_coder(1, 1512, dvbt.QAM16, dvbt.NH, dvbt.C1_2)
  static dvbt::inner_coder::sptr dvbt_inner_coder_0 = dvbt::inner_coder::make(1, 1512, dvbt::QAM16, dvbt::NH, dvbt::C1_2);
  
  // self.dvbt_energy_dispersal_0 = dvbt.energy_dispersal(1)
  static dvbt::energy_dispersal::sptr dvbt_energy_dispersal_0 = dvbt::energy_dispersal::make(1);
  
  // self.dvbt_dvbt_map_0 = dvbt.dvbt_map(1512, dvbt.QAM16, dvbt.NH, dvbt.T2k, 1)
  static dvbt::dvbt_map::sptr dvbt_dvbt_map_0 = dvbt::dvbt_map::make(1512, dvbt::QAM16, dvbt::NH, dvbt::T2k, 1);
  
  // self.dvbt_convolutional_interleaver_0 = dvbt.convolutional_interleaver(136, 12, 17)
  static dvbt::convolutional_interleaver::sptr dvbt_convolutional_interleaver_0 = dvbt::convolutional_interleaver::make(136, 12, 17);
  
  // self.dvbt_bit_inner_interleaver_0 = dvbt.bit_inner_interleaver(1512, dvbt.QAM16, dvbt.NH, dvbt.T2k)
  static dvbt::bit_inner_interleaver::sptr dvbt_bit_inner_interleaver_0 = dvbt::bit_inner_interleaver::make(1512, dvbt::QAM16, dvbt::NH, dvbt::T2k);
  
  // self.digital_ofdm_cyclic_prefixer_0 = digital.ofdm_cyclic_prefixer(2048, 2048+64, 0, '')
  static digital::ofdm_cyclic_prefixer::sptr digital_ofdm_cyclic_prefixer_0 = digital::ofdm_cyclic_prefixer::make(2048, 2048+64, 0, "");
  
  // self.blocks_multiply_const_vxx_0 = blocks.multiply_const_vcc((0.0022097087, ))
  std::vector<gr_complex> constant;
  constant.push_back(gr_complex(0.0022097087, 0.0));
  static blocks::multiply_const_vcc::sptr blocks_multiply_const_vxx_0 = blocks::multiply_const_vcc::make(constant);
  
  // self.blocks_file_source_0 = blocks.file_source(gr.sizeof_char*1, 'input', False)
  static blocks::file_source::sptr blocks_file_source_0 = blocks::file_source::make(sizeof(char)*1, argv[1], false);
  
  // self.blocks_file_source_0.set_begin_tag(pmt.PMT_NIL)
  blocks_file_source_0->set_begin_tag(pmt::PMT_NIL);
  
  // self.blocks_file_sink_0 = blocks.file_sink(gr.sizeof_gr_complex*1, 'output', False)
  static blocks::file_sink::sptr blocks_file_sink_0 = blocks::file_sink::make(sizeof(gr_complex)*1, argv[2], false);
  
  // self.blocks_file_sink_0.set_unbuffered(False)
  blocks_file_sink_0->set_unbuffered(false);
  
  
  tb->connect(blocks_file_source_0, 0, dvbt_energy_dispersal_0, 0);
  tb->connect(blocks_multiply_const_vxx_0, 0, rational_resampler_xxx_0, 0);
  tb->connect(digital_ofdm_cyclic_prefixer_0, 0, blocks_multiply_const_vxx_0, 0);
  tb->connect(dvbt_bit_inner_interleaver_0, 0, dvbt_symbol_inner_interleaver_0, 0);
  tb->connect(dvbt_convolutional_interleaver_0, 0, dvbt_inner_coder_0, 0);
  tb->connect(dvbt_dvbt_map_0, 0, dvbt_reference_signals_0, 0);
  tb->connect(dvbt_energy_dispersal_0, 0, dvbt_reed_solomon_enc_0, 0);
  tb->connect(dvbt_inner_coder_0, 0, dvbt_bit_inner_interleaver_0, 0);
  tb->connect(dvbt_reed_solomon_enc_0, 0, dvbt_convolutional_interleaver_0, 0);
  tb->connect(dvbt_reference_signals_0, 0, fft_vxx_0, 0);
  tb->connect(dvbt_symbol_inner_interleaver_0, 0, dvbt_dvbt_map_0, 0);
  tb->connect(fft_vxx_0, 0, digital_ofdm_cyclic_prefixer_0, 0);
  tb->connect(rational_resampler_xxx_0, 0, blocks_file_sink_0, 0);
  
  tb->run();

  return 0;
}











