#pragma once
#ifndef __ALLOCATIONS_H
#define __ALLOCATIONS_H


char* createDynStr(const char* msg);
char* myGets(char* buffer, int size);
void makeUpper(char* str, int size);
void cutSpace(char* str);
int isNum(char* str);
void* safeRealloc(void* base, size_t newByteCount);

#endif