#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "SHA256 en C/sha256_utils.h"


#ifndef TRANSACTION_H
#define TRANSACTION_H


typedef struct s_Transaction {
    char* trans;
    Transaction next;
} *Transaction;


void genAleaTrans (Block block, int maxTrans);

#endif
