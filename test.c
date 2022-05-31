#include"Slist.h"

void SlistTest1()
{
	SLTNode* plist=NULL;
	SListPushBack(&plist,1);
	SListPushBack(&plist,2);

	SListPushFront(&plist,5);
	SListPushFront(&plist,4);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPopFront(&plist);
	SListPrint(plist);

}
void SListTest2()
{
	SLTNode* plist=NULL;
	SLTNode* pos;
	int i=0;
	SListPushBack(&plist,1);
	SListPushBack(&plist,2);
	SListPushBack(&plist,3);
	SListPrint(plist);
	pos=SListFind(plist,2);
	//查找所有的2
	//while(pos)
	//{
	//	printf("第%d个2，位置%p\n",++i,pos);
	//	pos=SListFind(pos->next,2);
	//}
	if(pos==NULL)
	{
		printf("SListFind failed");
		exit(-1);
	}
	else
	{
	SListInsert(&plist,pos,5);
	}
	SListPrint(plist);
	pos=SListFind(plist,1);
	SListErase(&plist,pos);
	SListPrint(plist);
}
void SListTest3()
{
	SLTNode* plist=NULL;
	SLTNode* pos;
	SListPushBack(&plist,1);
	SListPushBack(&plist,2);
	SListPrint(plist);
	pos=SListFind(plist,1);
	SListInsertAfter(pos,3);
	SListPrint(plist);
	pos=SListFind(plist,3);
	SListEraseAfter(pos);
	SListPrint(plist);
	SListDestroy(&plist);
}
int main()
{
	//SlistTest1();
	//SListTest2();
	SListTest3();
}