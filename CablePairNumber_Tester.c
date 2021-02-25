/*
 * CablePairNumber_Tester.c
 *
 *  Created on: Feb 22, 2021
 *      Author: PUL1KOR
 */

#include <stdio.h>
#include <assert.h>
#include "CablePairTester_CommonCfg.h"
#include "CablePairNumber_Tester.h"

extern int numberOfMajorColors_int;
extern int numberOfMinorColors_int;

/*************************************************
 * Des: This function will fetch and print tha pair number. Also it will validate the test case
 * In : major --> MajorColor enum variable
 *      minor --> MinorColor enum variable
 *      expectedPairNumber
 */

void Fc_testPairToNumber(void)
{
	int pairNumber_int = 0xFF ,MjC_ref_int = 0xFF ,MnC_ref_int = 0xFF;
	/************************************USER Inputs********************************************************/
	Fc_UserInput_Handler(&pairNumber_int, &MjC_ref_int ,&MnC_ref_int,3);
	/********************************System Calculation*********************************************************/
	ColorPair_tst colorPair_st;
	colorPair_st.majorColor_en = MjC_ref_int - MAJOR_COLOUR_REFERENCE_NO_OFFSET;
	colorPair_st.minorColor_en = MnC_ref_int - MINOR_COLOUR_REFERENCE_NO_OFFSET;
	int CalculatedPairNumber_int = Fc_GetPairNumberFromColor(&colorPair_st);
	printf("Got pair number %d\n", CalculatedPairNumber_int);
	assert(CalculatedPairNumber_int == pairNumber_int);
}/*end of void Fc_testPairToNumber*/

int Fc_GetPairNumberFromColor(const ColorPair_tst* colorPair_st)
{
    return colorPair_st->majorColor_en * numberOfMinorColors_int +
    		colorPair_st->minorColor_en + 1;
}/*end of int Fc_GetPairNumberFromColor*/
