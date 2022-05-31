#include"Slist.h"
void SListPrint(SLTNode* phead)
 {
	 SLTNode* cur=phead;
	 while(cur!=NULL)
	 {
		 printf("%d",cur->data);
		 cur=cur->next;
	 }
	 printf("NULL");
	 printf("\n");
}
SLTNode* BuyListNode(SLTDataType x)
{
	SLTNode* newnode=(SLTNode*)malloc(sizeof(SLTNode));
	if(newnode==NULL)
	{
		printf("malloc failed");
		exit(-1);
	}
	(newnode)->next=NULL;
	(newnode)->data=x;
	return newnode;
}
void SListPushBack(SLTNode** phead ,SLTDataType x)
{
	SLTNode* newnode=BuyListNode(x);
	assert(phead);
	if(*phead==NULL)
	{
		*phead=newnode;
	}
	else
	{
		SLTNode* tail=*phead;
	while((tail)->next!=NULL)
	{
		(tail)=(tail)->next;
	}
	
	((tail)->next)=newnode;
	}
}

void SListPushFront(SLTNode** phead ,SLTDataType x)
{
	SLTNode* cur=BuyListNode(x);
	assert(phead);
	cur->next=*phead;
	*phead=cur;
}

void SListPopBack(SLTNode** phead )
{
	SLTNode* tail=*phead;
	SLTNode* cur=*phead;
	assert(*phead);
	if((*phead)->next==NULL)
	{
		free(*phead);
		*phead=NULL;
	}
	else
	{
	while(tail->next!=NULL)
	{
		cur=tail;
		tail=tail->next;
	}

	/*while(cur->next!=tail)
	{
		cur=cur->next;
	}*/
	cur->next=NULL;
	free(tail);
	tail=NULL;
	}
}
// while(tail->next->next)
/*{
	tail=tail->next
 }
free(tail->next);
tail->next=NULL;*/	
void SListPopFront(SLTNode** phead )
{
	assert(phead);
	if(*phead!=NULL)
	{
		SLTNode* cur=*phead;
		*phead=cur->next;
		free(cur);
		cur=NULL;
	}
}

SLTNode* SListFind(SLTNode* phead,SLTDataType x)
{
	SLTNode* cur=phead;
	while(cur->data!=x)
	{
		cur=cur->next;
		if(cur==NULL)
			return NULL;
	}
	return cur;
}
void SListInsert(SLTNode** phead,SLTNode* pos,SLTDataType x)//ÔÚposÇ°É¾³ý
{
	SLTNode* pheadprv=*phead;
	SLTNode* newnode=BuyListNode(x);
	assert(phead);
	assert(pos);
	if(pos==*phead)
	{
		newnode->next=*phead;
		*phead=newnode;
	}
	else
	{
	while(pheadprv->next!=pos)
	{
		pheadprv=pheadprv->next;
	}
	pheadprv->next=newnode;
	newnode->next=pos;
	}
}
void SListErase(SLTNode** phead,SLTNode*pos)
{
	SLTNode* pheadprv=*phead;
	assert(phead);
	assert(pos);
	if(pos==*phead)
	{
		*phead=pos->next;
		free(pos);
		pos=NULL;
	}
	else
	{
	while(pheadprv->next!=pos)
	{
		pheadprv=pheadprv->next;
	}
	pheadprv->next=pos->next;
	free(pos);
	pos=NULL;
	}
}

void SListInsertAfter(SLTNode* pos,SLTDataType x)
{
	SLTNode* newnode=BuyListNode(x);
	assert(pos);
	newnode->next=pos->next;
	pos->next=newnode;
}
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	pos->next=pos->next->next;
	free(pos->next);
	pos->next=NULL;
}

void SListDestroy(SLTNode** phead)
{
	SLTNode* cur=*phead;
	assert(phead);
	while(cur)
	{
		*phead=(*phead)->next;
		free(cur);
		cur=*phead;
	}
}	