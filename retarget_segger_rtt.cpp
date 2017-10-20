//----------------------------------------------------------------------------
// Description: Alternative stdio read/write interface function for Segger RTT
// Copyright:   (c) 2017 Mark <0x6d61726b@gmail.com>
// License:     MIT License
// SVN:         $Id: retarget_segger_rtt.cpp 258 2017-10-20 22:28:51Z 0x6d61726b $
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//----------------------------------------------------------------------------
#include "platform/mbed_retarget_alt.h"
#include "SeggerRTT/SEGGER_RTT.h"


void retarget_stdio_init_alt(unsigned int fh)
{
    // initialize the Segger RTT interface
    SEGGER_RTT_Init();
}


int retarget_stdio_write_alt(unsigned int fh, const unsigned char *buffer, unsigned int length)
{
    // write the buffer content to the terminal
    return SEGGER_RTT_Write(0, buffer, length);
}


int retarget_stdio_read_alt(unsigned int fh, unsigned char *buffer, unsigned int length)
{
    // wait until a character becomes available
    while (!SEGGER_RTT_HasKey());
    
    // read the characters from the terminal into the buffer
    return SEGGER_RTT_Read(0, buffer, length);
}