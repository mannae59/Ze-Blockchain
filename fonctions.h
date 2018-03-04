#include "structures.h"

Blockchain initBlockchain (int difficulty);

void addBlock (Blockchain blockchain, int maxTrans);

Block genAleaBlock (int difficulty, int maxTrans, int index, char* previousHash);

void genAleaTrans (Block block, int maxTrans);

char* merkleRoot (Transaction transactionList);

void mine (int difficulty, Block block);

char* createHash(Block block);