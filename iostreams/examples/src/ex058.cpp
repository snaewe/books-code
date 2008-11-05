/*
author:  "Klaus Wittlich" <Klaus_Wittlich@sae.de> 

Based on source code published in the book "Standard C++ IOStreams 
and Locales" by Angelika Langer & Klaus Kreft, Copyright (c) 2000 by 
Addison Wesley Longman, Inc.

Permission to use, copy, and modify this software for any non-profit
purpose is hereby granted without fee.  Neither the author of this 
source code, Klaus Wittlich, nor the authors of the above mentioned 
book, Angelika Langer and Klaus Kreft, nor the publisher, Addison Wesley 
Longman, Inc., make any representations about the suitability of this 
software for any purpose.  It is provided "as is" without express or 
implied warranty.
*/

#include <iostream>
#include <stdio.h>
#include <ios>

using namespace ::std;

int main()
{
    //*
	// p. 58 {{{
    ios_base::sync_with_stdio(false);
	// }}}
    //*/

    cout << "Using cout, ";
    printf("Calling printf, ");
    cout << "Using cout again, ";
    printf("Calling printf");
    cout << endl;
    int i;
    for (i=0;i<100;++i) {
        printf("*%i*",i);			// printf - output - numbers are enclosed with *
        cout << "#" << i << "#";    // coiut  - output - numbers are enclosed with #
        if (i % 2)
            printf("\n");
        else
            cout << "\n";
    }

    return 0;
}

/* Input: No input
*/
/* Output: (It is with sync_with_stdio(false) and without the same)
Using cout, Calling printf, Using cout again, Calling printf
*0*#0#
*1*#1#
*2*#2#
*3*#3#
*4*#4#
*5*#5#
*6*#6#
*7*#7#
*8*#8#
*9*#9#
*10*#10#
*11*#11#
*12*#12#
*13*#13#
*14*#14#
*15*#15#
*16*#16#
*17*#17#
*18*#18#
*19*#19#
*20*#20#
*21*#21#
*22*#22#
*23*#23#
*24*#24#
*25*#25#
*26*#26#
*27*#27#
*28*#28#
*29*#29#
*30*#30#
*31*#31#
*32*#32#
*33*#33#
*34*#34#
*35*#35#
*36*#36#
*37*#37#
*38*#38#
*39*#39#
*40*#40#
*41*#41#
*42*#42#
*43*#43#
*44*#44#
*45*#45#
*46*#46#
*47*#47#
*48*#48#
*49*#49#
*50*#50#
*51*#51#
*52*#52#
*53*#53#
*54*#54#
*55*#55#
*56*#56#
*57*#57#
*58*#58#
*59*#59#
*60*#60#
*61*#61#
*62*#62#
*63*#63#
*64*#64#
*65*#65#
*66*#66#
*67*#67#
*68*#68#
*69*#69#
*70*#70#
*71*#71#
*72*#72#
*73*#73#
*74*#74#
*75*#75#
*76*#76#
*77*#77#
*78*#78#
*79*#79#
*80*#80#
*81*#81#
*82*#82#
*83*#83#
*84*#84#
*85*#85#
*86*#86#
*87*#87#
*88*#88#
*89*#89#
*90*#90#
*91*#91#
*92*#92#
*93*#93#
*94*#94#
*95*#95#
*96*#96#
*97*#97#
*98*#98#
*99*#99#
*/