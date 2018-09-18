/* -*- c++ -*- */
/* 
 * Copyright 2018 gr-fuzzing author.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_FUZZING_SECOND_BLOCK_H
#define INCLUDED_FUZZING_SECOND_BLOCK_H

#include <fuzzing/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace fuzzing {

    /*!
     * \brief <+description of block+>
     * \ingroup fuzzing
     *
     */
    class FUZZING_API second_block : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<second_block> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of fuzzing::second_block.
       *
       * To avoid accidental use of raw pointers, fuzzing::second_block's
       * constructor is in a private implementation
       * class. fuzzing::second_block::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace fuzzing
} // namespace gr

#endif /* INCLUDED_FUZZING_SECOND_BLOCK_H */

