/*
 * CablePairTester_CommonCfg.c
 *
 *  Created on: Feb 22, 2021
 *      Author: PUL1KOR
 */


#include "CablePairTester_CommonCfg.h"

const int MAX_COLORPAIR_NAME_CHARS = 16;

const char* MajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
const char* MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };

int numberOfMajorColors_int = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors_int = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

/**************
 * Description : This will create string of the passed colour pairs
 * In: ColorPair --> Structure pointer.
 *     buffer    --> Output string buffer pointer.
 *
 * OUT: None
 */
void Fc_ColorPairToString(const ColorPair_tst* colorPair_st, char* buffer)
{
	sprintf( buffer, "%s %s", 							\
			 MajorColorNames[colorPair_st->majorColor_en], 	\
			 MinorColorNames[colorPair_st->minorColor_en] 	\
		   );
}/*end of Fc_ColorPairToString*/
