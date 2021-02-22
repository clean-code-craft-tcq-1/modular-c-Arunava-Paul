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
const int MAX_COLORPAIR_NAME_CHARS = 16;

enum MajorColor_ten {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor_ten {BLUE, ORANGE, GREEN, BROWN, SLATE};
const char* MajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
const char* MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };

/*************************************/

int numberOfMajorColors_int = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors_int = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

typedef struct {
    enum MajorColor_ten majorColor_en;
    enum MinorColor_ten minorColor_en;
} ColorPair_tst;

void Fc_ColorPairToString(const ColorPair_tst* colorPair_st, char* buffer);
void Fc_testNumberToPair(int pairNumber_int, enum MajorColor_ten expectedMajor_en, enum MinorColor_ten expectedMinor_en);
ColorPair_tst Fc_GetColorFromPairNumber(int pairNumber_int);
void Fc_testPairToNumber(enum MajorColor_ten major_en, enum MinorColor_ten minor_en, int expectedPairNumber_int);
int Fc_GetPairNumberFromColor(const ColorPair_tst* colorPair_st);

#endif /* CABLEPAIRTESTER_COMMONCFG_H_ */
