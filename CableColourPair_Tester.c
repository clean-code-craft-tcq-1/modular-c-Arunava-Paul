/*
 * CableColourPair_Tester.c
 *  Created on: Feb 22, 2021
 *      Author: PUL1KOR
 */
#include <stdio.h>
#include <assert.h>
#include "CablePairTester_CommonCfg.h"
#include "CableColourPair_Tester.h"
extern const int MAX_COLORPAIR_NAME_CHARS;
extern int numberOfMajorColors_int;
extern int numberOfMinorColors_int;
/*****************************************
 * This Function takes the user input cable pair number and test if the connected colour combination is correct or not. IN, OUT : Void
 */
void Fc_testNumberToPair(void)
{
	int pairNumber_int = 0xFF ,MjC_ref_int = 0xFF ,MnC_ref_int = 0xFF,expectedMajor_int,expectedMinor_int;
	char colorPairNames_ch[MAX_COLORPAIR_NAME_CHARS];
	/************************************USER Inputs********************************************************/
	Fc_UserInput_Handler(&pairNumber_int, &MjC_ref_int ,&MnC_ref_int);
    /********************************System Calculation*********************************************************/
	ColorPair_tst colorPair_st = Fc_GetColorFromPairNumber(pairNumber_int); /*Get the colour combo from the pair number*/
	Fc_ColorPairToString(&colorPair_st, colorPairNames_ch);/*Coverting into string*/
	printf("Got pair %s\n", colorPairNames_ch);/*System calculated COLOUR pair */
	/***********************************************************************************************************/
	enum MajorColor_ten expectedMajor_en = MjC_ref_int - MAJOR_COLOUR_REFERENCE_NO_OFFSET;
	enum MinorColor_ten expectedMinor_en = MnC_ref_int - MINOR_COLOUR_REFERENCE_NO_OFFSET;
	assert(colorPair_st.majorColor_en == expectedMajor_en);
	assert(colorPair_st.minorColor_en == expectedMinor_en);
}/*end of void Fc_testNumberToPair*/
/*****This function computes the colour commbo from a given pair number: IN : Pair number, Out : ColourPair_tst structure********/
ColorPair_tst Fc_GetColorFromPairNumber(int pairNumber_int)
{
    ColorPair_tst colorPair_st;
    int zeroBasedPairNumber_int = pairNumber_int - 1;
    colorPair_st.majorColor_en = (enum MajorColor_ten)(zeroBasedPairNumber_int / numberOfMinorColors_int);
    colorPair_st.minorColor_en = (enum MinorColor_ten)(zeroBasedPairNumber_int % numberOfMinorColors_int);
    return colorPair_st;
}/*end of ColorPair_tst Fc_GetColorFromPairNumber*/
