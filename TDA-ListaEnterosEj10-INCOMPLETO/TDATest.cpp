//
// Created by muribe on 10/10/23.
//

#include "TDATest.h"

TDATest::TDATest() {
	this->aloja = 0;
}

TDATest::~TDATest() {
	delete this->aloja;
}

void TDATest::setAloja(TDATest * TEDA) {
	this->aloja = TEDA->aloja;
}