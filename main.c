/*
 * main.c
 *  Created on: Feb 22, 2021
 *      Author: PUL1KOR
 */
#include <stdio.h>
#include "CablePairTester_CommonCfg.h"
#include "CablePairNumber_Tester.h"
#include "CableColourPair_Tester.h"
/********************
 * Des: Main function. This will call the Colour pair testing functions.
 * Input : None
 * Output: None
 */
int main()
{
	char key_ip;
	printf("-------Telecom Cable pair tester code---------\n\n"
			"available major colours :  WHITE, RED, BLACK, YELLOW, VIOLET \n available minor colours :  BLUE, ORANGE, GREEN, BROWN, SLATE\n"
			"For reference table press 'a' otherwise to test combination press 'b'\n\n ");
#if(USER_INPUT_MODE_ACTIVALED == TRUE)
	while(!((key_ip== 'a') || (key_ip== 'b')))
		scanf("%c",&key_ip);/*Scan the character until the user press correct data*/
	key_ip == 'a'? Fc_Reference_Table():Fc_Test_pairCombo();
#else
	/**Since Github does not support SCANF run manual function calling has been configured**/
	Fc_Reference_Table();
	Fc_Test_pairCombo();
#endif
    return 0;
}/*end of main*/

/*This function will trigger the pair no to colour or colour to pair tester function**/
void Fc_Test_pairCombo(void)
{
	char key_ip;
	printf("---Cable pair tester--\n\n To test the pair number to Colour combo press 'a' , To test the colour combo to pair number press 'b'\n\n ");
#if(USER_INPUT_MODE_ACTIVALED == TRUE)
	while(!((key_ip== 'a') || (key_ip== 'b')))
			scanf("%c",&key_ip);/*Scan the character until the user press correct data*/
	printf("Please ");
	key_ip == 'a'? Fc_testPairToNumber():Fc_testNumberToPair();
#else
	Fc_testPairToNumber();
	Fc_testNumberToPair();
#endif
}/*end of Fc_Test_pairCombo*/
