#ifndef LOCAL_H
#define LOCAL_H
#define MAX_LOCAIS 100

typedef struct {
    char nome[50];
float x;
    float y;
} Local;
void cadastrarLocal(Local locais[], int *numLocais);
void listarLocais(Local locais[], int numLocais);
void atualizarLocal(Local locais[], int numLocais);
void removerLocal(Local locais[], int *numLocais);
#endif