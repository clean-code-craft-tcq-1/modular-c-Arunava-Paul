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

enum MajorColor_ten {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor_ten {BLUE, ORANGE, GREEN, BROWN, SLATE};

/*************************************/

typedef struct {
    enum MajorColor_ten majorColor_en;
    enum MinorColor_ten minorColor_en;
} ColorPair_tst;

void Fc_ColorPairToString(const ColorPair_tst* colorPair_st, char* buffer);


#endif /* CABLEPAIRTESTER_COMMONCFG_H_ */
