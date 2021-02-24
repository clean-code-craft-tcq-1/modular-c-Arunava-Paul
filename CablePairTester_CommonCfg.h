/*
 * CablePairTester_CommonCfg.h
 *
 *  Created on: Feb 22, 2021
 *      Author: PUL1KOR
 */

#ifndef CABLEPAIRTESTER_COMMONCFG_H_
#define CABLEPAIRTESTER_COMMONCFG_H_

#include <stdio.h>
#include <assert.h>

/************
 * Colour Pair as per standard
 ************/

enum MajorColor_ten {WHITE=0, RED, BLACK, YELLOW, VIOLET};
enum MinorColor_ten {BLUE=0, ORANGE, GREEN, BROWN, SLATE};

/******WHITE = 1, RED= 2, BLACK=3, YELLOW=4, VIOLET=5, BLUE=6, ORANGE=7, GREEN=8, BROWN=9, SLATE=10*********/
#define MAJOR_COLOUR_REFERENCE_NO_OFFSET 1
#define MINOR_COLOUR_REFERENCE_NO_OFFSET 6
/*************************************/

typedef struct {
    enum MajorColor_ten majorColor_en;
    enum MinorColor_ten minorColor_en;
} ColorPair_tst;

void Fc_ColorPairToString(const ColorPair_tst* colorPair_st, char* buffer);
void Fc_Reference_Table(void);
void Fc_Test_pairCombo(void);
void Fc_UserInput_Handler(int *cable_pair_no,int *major_colour_en_no,int *minor_colour_en_no );
extern ColorPair_tst Fc_GetColorFromPairNumber(int pairNumber_int);
#endif /* CABLEPAIRTESTER_COMMONCFG_H_ */
