/*
 * CablePairTester_CommonCfg.c
 *  Created on: Feb 22, 2021  *      Author: PUL1KOR
 */
#include "CablePairTester_CommonCfg.h"
const int MAX_COLORPAIR_NAME_CHARS = 16;
const int TOTAL_PAIR_NUMBER = 25;
const char* MajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
const char* MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
int numberOfMajorColors_int = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors_int = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);
/**** Description : This will create string of the passed colour pairs|| In: ColorPair --> Structure pointer.|buffer    --> Output string buffer pointer.||OUT: None** */
void Fc_ColorPairToString(const ColorPair_tst* colorPair_st, char* buffer)
{
	sprintf( buffer, "%s %s", MajorColorNames[colorPair_st->majorColor_en], MinorColorNames[colorPair_st->minorColor_en]);
}/*end of Fc_ColorPairToString*/
/******Description : This will Print the Reference table for the User|| * In: void * OUT: void ***/
void Fc_Reference_Table(void)
{
	int idx = 1;
	ColorPair_tst colorPair_st;
	printf("********** Reference Table ************* \nPair_no     Major_Colour       Minor_colour\n");
	for(idx = 1 ; idx <= numberOfMajorColors_int ; idx++)
	{
		colorPair_st = Fc_GetColorFromPairNumber(idx);
		printf("%d           %s              %s \n", idx ,MajorColorNames[colorPair_st.majorColor_en],MinorColorNames[colorPair_st.minorColor_en] );
	}
	printf("*******End of Reference Table ********** \n");
}/*end of Fc_Reference_Table*/
/*This function takes the user input and pass to the other functins. Out Void || IN : Major , minor colour reference number pointer and Pair Number pointer*/
void Fc_UserInput_Handler(int *cable_pair_no,int *major_colour_en_no,int *minor_colour_en_no,int choice_int )
{
#if(USER_INPUT_MODE_ACTIVALED == TRUE)
	    (void)(choice_int);// not used
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
#else
	/*keeping the same case as original files*/
	switch(choice_int)
	{
	case 1: *cable_pair_no = 4 ; *major_colour_en_no = 1 ; *minor_colour_en_no = 9  ; break;
	case 2: *cable_pair_no = 5 ; *major_colour_en_no = 1 ; *minor_colour_en_no = 10 ; break;
	case 3: *cable_pair_no = 12; *major_colour_en_no = 3 ; *minor_colour_en_no = 7  ; break;
	case 4: *cable_pair_no =15 ; *major_colour_en_no = 5 ; *minor_colour_en_no = 10 ; break;
	default:*cable_pair_no =15 ; *major_colour_en_no = 5 ; *minor_colour_en_no = 10 ; break;
	}
#endif
}/*end of Fc_UserInput_Handler*/
