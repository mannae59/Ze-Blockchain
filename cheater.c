#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

void cheaterBlock (Blockchain blockchain, int index){
	int i;
	Block block = NULL;
	//on parcourt la liste jusqu'au bloc qui nous intéresse
	for (i = 0; i <= index; i++){
		block = block->next;
	}
	//on refait les liens et on efface le bloc
	//pour cela on atteint le bloc suivant notre cible
	block->previous = block->previous->previous;
	free(block->previous->next);
	block->previous->next = block;
	//on recalcule le hash du bloc
	while (block != NULL){
		mine (blockchain->difficulty, block);
		block = block->next;
	}

}

void cheaterTrans (Blockchain blockchain, int index, int numTrans){
	int i;
	Block block = blockchain->genesis;
	Transaction transaction = NULL;
	Transaction delTrans = NULL;
	//on parcourt la liste jusqu'au bloc qui nous intéresse
	for (i = 0; i < index; i++){
		block = block->next;
	}
	//on parcourt la liste de transactions jusqu'à celle qui nous intéresse
	transaction = block->transactionList;
	for (i = 0; i < numTrans - 1; i++){
		transaction = transaction->next;
	}
	//on refait les liens et on efface la transaction
	delTrans = transaction->next;
	transaction->next = transaction->next->next;
	free(delTrans);
	//on recalcule le Merkle Root et le hash du bloc
	block->hashRoot = merkleRoot (block->transactionList);
	while (block != NULL){
		mine (blockchain->difficulty, block);
		block = block->next;
	}

}