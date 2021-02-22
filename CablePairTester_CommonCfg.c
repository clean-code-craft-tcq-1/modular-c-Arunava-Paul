/*
 * CablePairTester_CommonCfg.c
 *
 *  Created on: Feb 22, 2021
 *      Author: PUL1KOR
 */


#include <CablePairTester_CommonCfg.h>

/**************
 * Description : This will create string of the passed colour pairs
 * In: ColorPair --> Structure pointer.
 *     buffer    --> Output string buffer pointer.
 *
 * OUT: None
 */
void Fc_ColorPairToString(const ColorPair* colorPair, char* buffer)
{
	sprintf( buffer, "%s %s", 							\
			 MajorColorNames[colorPair->majorColor], 	\
			 MinorColorNames[colorPair->minorColor] 	\
		   );
}/*end of Fc_ColorPairToString*/
