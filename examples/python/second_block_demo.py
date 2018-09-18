#!/usr/bin/env python2

from gnuradio import blocks
from gnuradio import gr
import fuzzing
import pmt


class fuzzing_block(gr.top_block):

    def __init__(self):
        gr.top_block.__init__(self, "fuzzing Block")

        ##################################################
        # Blocks
        ##################################################
        self.fuzzing_qwerty_ff_0 = fuzzing.second_block()
        self.blocks_file_source_0 = blocks.file_source(gr.sizeof_char*1, 'input', False)
        self.blocks_file_source_0.set_begin_tag(pmt.PMT_NIL)
        self.blocks_file_sink_0 = blocks.file_sink(gr.sizeof_char*1, 'output', False)
        self.blocks_file_sink_0.set_unbuffered(False)

        ##################################################
        # Connections
        ##################################################
        self.connect((self.blocks_file_source_0, 0), (self.fuzzing_qwerty_ff_0, 0))
        self.connect((self.fuzzing_qwerty_ff_0, 0), (self.blocks_file_sink_0, 0))

tb = fuzzing_block()
tb.start()
tb.wait()
