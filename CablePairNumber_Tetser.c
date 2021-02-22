/*
 * CablePairNumber_Tetser.c
 *
 *  Created on: Feb 22, 2021
 *      Author: PUL1KOR
 */

#include <stdio.h>
#include <assert.h>
#include "CablePairNumber_Tetser.h"
/*************************************************
 * Des: This function will fetch and print tha pair number. Also it will validate the test case
 * In : major --> MajorColor enum variable
 *      minor --> MinorColor enum variable
 *      expectedPairNumber
 */

void Fc_testPairToNumber(enum MajorColor_ten major_en, enum MinorColor_ten minor_en, int expectedPairNumber_int)
{
    ColorPair_tst colorPair_st;
    colorPair_st.majorColor_en = major_en;
    colorPair_st.minorColor_en = minor_en;
    int pairNumber_int = Fc_GetPairNumberFromColor(&colorPair_st);
    printf("Got pair number %d\n", pairNumber_int);
    assert(pairNumber_int == expectedPairNumber_int);
}/*end of void Fc_testPairToNumber*/

int Fc_GetPairNumberFromColor(const ColorPair_tst* colorPair_st)
{
    return colorPair_st->majorColor_en * numberOfMinorColors_int +
    		colorPair_st->minorColor_en + 1;
}/*end of int Fc_GetPairNumberFromColor*/
