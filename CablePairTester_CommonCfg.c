/*
 * CablePairTester_CommonCfg.c
 *
 *  Created on: Feb 22, 2021
 *      Author: PUL1KOR
 */
#include "CablePairTester_CommonCfg.h"

const int MAX_COLORPAIR_NAME_CHARS = 16;
const int TOTAL_PAIR_NUMBER = 25;
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

/**************
 * Description : This will Print the Reference table for the User
 * In: void
 * OUT: void
 */
void Fc_Reference_Table(void)
{
	int idx = 1;
	ColorPair_tst colorPair_st;
	printf("********** Reference Table ************* \n");
	printf("Pair_no     Major_Colour       Minor_colour\n");
	for(idx ; idx <= numberOfMajorColors_int ; idx++)
	{
		colorPair_st = Fc_GetColorFromPairNumber(idx);
		printf("%d           %s              %s \n", idx ,MajorColorNames[colorPair_st->majorColor_en],MinorColorNames[colorPair_st->minorColor_en] );
	}
	printf("*******End of Reference Table ********** \n");
}/*end of Fc_Reference_Table*/

void Fc_UserInput_Handler(int *cable_pair_no,int *major_colour_en_no,int *minor_colour_en_no )
{
		printf("\n---Colour Combo to pair tester---\n\n According to pair number standard 1-25 is available.\n"
			   "The numbers corresponding to the colours are as followed : \n  WHITE = 1, RED= 2, BLACK=3, YELLOW=4, VIOLET=5, BLUE=6, ORANGE=7, GREEN=8, BROWN=9, SLATE=10\n");
		printf("\nPlease enter the pair no:");
		while(!((*cable_pair_no <= 25) && (*cable_pair_no >= 1)))
			scanf("%d",cable_pair_no);/*scan till the user give proper pair number*/
		printf("You have entered : %d",*cable_pair_no);
		printf("\nEnter the major colour no and minor colour number with a space : ");
		while(!(((*major_colour_en_no <= 5) && (*major_colour_en_no >= 1)) && ((*minor_colour_en_no <= 10) && (*minor_colour_en_no >= 6))))
		        scanf("%d %d",major_colour_en_no,minor_colour_en_no);/*scan till the user give proper reference number*/
		printf("\nYou have entered : major_colour %s , minor_colour %s\n",MajorColorNames[(*major_colour_en_no) - MAJOR_COLOUR_REFERENCE_NO_OFFSET],MinorColorNames[(*minor_colour_en_no) - MINOR_COLOUR_REFERENCE_NO_OFFSET]);
}
