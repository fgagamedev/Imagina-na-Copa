#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#ifndef RESOURCE_H
#define RESOURCE_H

// Image List Manager
struct ILM{
	int s_id;
	int s_instance;
	SDL_Texture *s_texture;
	struct ILM *Prox;
	ILM(){s_id=0, s_instance=0, s_texture=NULL, Prox=NULL;}
};

extern bool ILM_IfEmpty(struct ILM *pList);
extern bool ILM_SearchNode(struct ILM *pList, int id);
extern int ILM_VerifyInstance(struct ILM *pList, int id);
extern struct ILM *ILM_NewNode(struct ILM *pList, int id, SDL_Texture *texture);
extern struct ILM *ILM_FreeNode(struct ILM *pList, int id);
extern struct ILM *ILM_PlusInstance(struct ILM *pList, int id);
extern struct ILM *ILM_MinusInstance(struct ILM *pList, int id);

#endif