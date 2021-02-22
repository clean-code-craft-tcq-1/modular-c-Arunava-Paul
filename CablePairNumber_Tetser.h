/*
 * CablePairNumber_Tetser.h
 *
 *  Created on: Feb 23, 2021
 *      Author: PUL1KOR
 */

#ifndef CABLEPAIRNUMBER_TETSER_H_
#define CABLEPAIRNUMBER_TETSER_H_


void Fc_testPairToNumber(enum MajorColor_ten major_en, enum MinorColor_ten minor_en, int expectedPairNumber_int);
int Fc_GetPairNumberFromColor(const ColorPair_tst* colorPair_st);

#endif /* CABLEPAIRNUMBER_TETSER_H_ */
