#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;
typedef struct SListNode//存放数据和下一块内存的地址（节点）
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** phead ,SLTDataType x);
void SListPushFront(SLTNode** phead ,SLTDataType x);

void SListPopBack(SLTNode** phead );
void SListPopFront(SLTNode** phead );

SLTNode* SListFind(SLTNode* phead,SLTDataType x);
void SListInsert(SLTNode** phead,SLTNode* pos,SLTDataType x);
void SListErase(SLTNode** phead,SLTNode*pos);

void SListInsertAfter(SLTNode* pos,SLTDataType x);
void SListEraseAfter(SLTNode* pos);

void SListDestroy(SLTNode** phead);