/*
 * main.c
 *
 *  Created on: Feb 22, 2021
 *      Author: PUL1KOR
 */


#include <CablePairTester_CommonCfg.h>

/********************
 *
 * Des: Main function. This will call the Colour pair testing functions.
 * Input : None
 * Output: None
 *
 */

int main()
{
	/*********
	 * available major colours :  WHITE, RED, BLACK, YELLOW, VIOLET
	 * available minor colours :  BLUE, ORANGE, GREEN, BROWN, SLATE
	 * other colours are invalid. Passing will return error.
	 * "https://en.wikipedia.org/wiki/25-pair_color_code" fore more details
	 */
    Fc_testNumberToPair(4, WHITE, BROWN);
    Fc_testNumberToPair(5, WHITE, SLATE);
    Fc_testPairToNumber(BLACK, ORANGE, 12);
    Fc_testPairToNumber(VIOLET, SLATE, 25);
    return 0;
}
