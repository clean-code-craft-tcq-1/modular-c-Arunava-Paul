/*
 * CableColourPair_Tetser.c
 *
 *  Created on: Feb 22, 2021
 *      Author: PUL1KOR
 */

#include "CablePairTester_CommonCfg.h"

void Fc_testNumberToPair(int pairNumber_int, enum MajorColor_ten expectedMajor_en, enum MinorColor_ten expectedMinor_en)
{
	ColorPair_tst colorPair_st = Fc_GetColorFromPairNumber(pairNumber_int);
	char colorPairNames_ch[MAX_COLORPAIR_NAME_CHARS];
	ColorPairToString(&colorPair_st, colorPairNames_ch);
	printf("Got pair %s\n", colorPairNames_ch);
	assert(colorPair_st.majorColor_en == expectedMajor_en);
	assert(colorPair_st.minorColor_en == expectedMinor_en);
}/*end of void Fc_testNumberToPair*/

ColorPair_tst Fc_GetColorFromPairNumber(int pairNumber_int)
{
    ColorPair_tst colorPair_st;
    int zeroBasedPairNumber_int = pairNumber_int - 1;
    colorPair_st.majorColor_en = (enum MajorColor_ten)(zeroBasedPairNumber_int / numberOfMinorColors_int);
    colorPair_st.minorColor_en = (enum MinorColor_ten)(zeroBasedPairNumber_int % numberOfMinorColors_int);
    return colorPair_st;
}/*end of ColorPair_tst Fc_GetColorFromPairNumber*/
