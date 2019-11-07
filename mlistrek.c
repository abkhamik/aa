#include <stdio.h>
#include <stdlib.h>
#include "listrek.h"


int main()
{
	List L=Nil, L1=Nil, L2=Nil,L3=Nil, L4=Nil, L5=Nil, L6=Nil;
	int Min=0, Max=0;
	
	L=Konso(10, L);
	L=Konso(-10, L);
	L=Konso(1, L);
	L=Konso(5, L);
	L=Konso(6, L);
	
	//PrintList(L);
	//printf("\n");
	/*
	L2=Konso(10, L2);
	L2=Konso(-10, L2);
	L2=Konso(1, L2);
	L2=Konso(10, L2);
	L2=Konso(6, L2);
	PrintList(L2);
	printf("\n");
	*/
	//printf("%d", IsEmpty(L));
	
	
	//PrintList(L);
	
	//printf("\na");
	/*
	MinMax(L, &Min, &Max);
	printf("%d\n%d\n", Min, Max);
	printf("%d\n", SumList(L));
	*/
	//printf("a");
	//printf("%d\n", ListCompare(L, L2));
	
	printf("Average List\n");
	printf("%f\n", AverageList(L));

	printf("L :\n");
	PrintList(L);
	printf("\n");
	printf("L1 :\n");
	PrintList(L1);
	printf("\n");
	printf("L1 :\n");
	PrintList(L2);
	printf("\n");
	SplitOnX(L, 1, &L1, &L2);
	PrintList(L1);
	printf("\n");
	PrintList(L2);
	printf("\n");
	
	printf("InverseList\n");
	
	L3=InverseList(L);
	PrintList(L3);
	
	printf("IsAllExist\n");
	L4=Konso(10, L4);
	L4=Konso(0, L4);
	L4=Konso(1, L4);
	L4=Konso(5, L4);
	L4=Konso(6, L4);
	
	printf("%d\n", IsAllExist(L, L4));
	
	printf("SplitPosNeg\n");
	
	SplitPosNeg(L, &L5, &L6);
	PrintList(L5);
	printf("\n");
	PrintList(L6);
	printf("\n");
	
	
	
	
	return 0;
}
