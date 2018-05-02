#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "blockchain.h"
#include "transaction.h"

#ifndef CHEATER_H
#define CHEATER_H

void cheaterBlock (Blockchain blockchain, int index);
void cheaterTrans (Blockchain blockchain, int index, int numTrans);



#endif
