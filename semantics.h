#ifndef SEMANTICS_H
#define SEMANTICS_H

#define UNDEF 0
#define INT_TYPE 1
#define REAL_TYPE 2
#define CHAR_TYPE 3
#define STRING_TYPE 4
#define BOOL_TYPE 5
#define ARRAY_TYPE 6
#define POINTER_TYPE 7
#define FUNCTION_TYPE 8
#define VOID_TYPE 9

#define NONE 0
#define ARITH_OP 1
#define ARITH_ASSIGN_OP 2
#define INCR_OP 3
#define BOOL_OP 4
#define NOT_OP 5
#define REL_OP 6
#define EQU_OP 7

typedef struct RevisitQueueStruct {
    StorageNode* entry;
    char* storage_name;
    int revisit_type;
    int** arg_types;
    int* arg_count;
    int call_count;
    void** nodes;
    int assign_count;
    struct RevisitQueueStruct* next;
} RevisitQueue;

static RevisitQueue* queue;

void pushToQueue(StorageNode*, char*, int);
RevisitQueue* searchQueue(const char*);
RevisitQueue* searchPrevQueue(const char*);
int revisit(const char*);
int funcDeclaration(const char*, int, int, Argument*);
int funcArgCheck(const char*, int, int**, int*);
void printRevisitQueue(FILE*);
int getResultType(int, int, int);
void typeError(int, int, int);

#endif