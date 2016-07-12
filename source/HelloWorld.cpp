/*
The MIT License (MIT)

Copyright (c) 2016 Lancaster University.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include "MicroBit.h"

MicroBit uBit;

void onButtonA(MicroBitEvent)
{
    uBit.display.scroll("HELLO");
}

void onButtonB(MicroBitEvent)
{
    auto str = "DARYL";
    uBit.display.scroll(str);
}

int main()
{
    uBit.init();

    MicroBitImage smiley("0,0,0,0,0\n0,255,0,255,0\n0,0,0,0,0\n255,0,0,0,255\n,0,255,255,255,0\n");
    uBit.display.print(smiley);

    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, onButtonB);

    // We're done. Release this fiber back to the scheduler.
    // This is a special case for main - exiting main() has different semantics than any other funciton in C!
    // Alternatively, you could do this:
    //
    // while(1)
    //     uBit,sleep(100);
    //
    // But releasing the fiber is more memory efficient...
    release_fiber();
}

