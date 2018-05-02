#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "SHA256 en C/sha256_utils.h"
#include "transaction.h"


#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

typedef struct s_Blockchain{
    int difficulty;
    int size;
    Block genesis;//PREMIER BLOCK
}*Blockchain;

typedef struct s_Block{
    int index;
    char* timestamp;
    char* previousHash;
    int nbTransaction;
    Transaction transactionList;
    char* hashRoot;
    char* hashBlock;
    int nonce;
    Block next;
    Block previous;
}*Block;



genAleaBlock (int difficulty, int maxTrans, int index, char* previousHash);
void addBlock (Blockchain blockchain, int maxTrans);
Blockchain initBlockchain (int difficulty);
char* merkleRoot (Transaction transactionList,int maxTrans);
void mine (int difficulty, Block block);

#endif
