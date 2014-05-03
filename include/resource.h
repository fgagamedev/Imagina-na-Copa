#ifndef RESOURCE_H
#define RESOURCE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Image List Manager
struct ILM{
	int s_id;
	int s_instance;
	SDL_Texture *s_texture;
	struct ILM *Prox;
	ILM(){instance=0;texture=NULL;Prox=NULL}
};

bool ILM_IfEmpty(ILM *pList)
{
	if(pList==NULL)
		return true;
	else
		return false;
}

bool ILM_SearchNode(ILM *pList, int id)
{
	ILM *pAux;
	pAux = pList;
	while((pAux->s_id!=id)&&(pAux->Prox!=NULL))
	{
		pAux = pAux->Prox;
	}
	if(pAux->s_id!=id)
		return false;
	else
		return true;	
}

int ILM_VerifyInstance(ILM *pList, int id)
{
	ILM *pAux;
	pAux = pList;
	while(pAux->s_id!=id)
		pAux = pAux->Prox;
	return pAux->s_instance;
}

ILM *ILM_NewNode(ILM *pList, int id, SDL_Texture *texture)
{
	ILM *pNewNode;
	pNewNode = (ILM*) malloc(sizeof(ILM));
	pNewNode->s_id = id
	pNewNode->s_instance = 1;
	pNewNode->s_texture = texture;
	pNewNode->Prox = pList;
	pList = pNewNode;
	return pList;
}

ILM *ILM_FreeNode(ILM *pList, int id)
{
	if(pList->s_id==id)
	{
		ILM *pAux;
		pAux = pList;
		pList = pAux->Prox;
		free(pAux);
		return pList;
	}
	else
	{
		ILM *pBefore;
		pBefore = pList;
		while(pBefore->Prox->s_id!=id)
			pBefore = pBefore->Prox;
		if(pBefore->Prox->Prox!=NULL)
		{
			ILM *pAfter;
			pAfter = pBefore->Prox->Prox;
			free(pBefore->Prox);
			pBefore->Prox=pAfter;
		}
		else
		{
			free(pBefore->Prox)
			pBefore->Prox = NULL;
		}
		return pList;
	}
}

ILM *ILM_PlusInstance(ILM *pList, int id)
{
	ILM *pAux;
	pAux = pList;
	while(pAux->s_id!=id)
		pAux = pAux->Prox;
	pAux->s_instance++;
	return pList;
}

ILM *ILM_MinusInstance(ILM *pList, int id)
{
	ILM *pAux;
	pAux = pList;
	while(pAux->s_id!=id)
		pAux = pAux->Prox;
	pAux->s_instance--;
	return pList;
}