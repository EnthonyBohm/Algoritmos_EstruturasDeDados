#ifndef MAIN_H
#define MAIN_H

struct matrix{
    struct matrix *right;
    struct matrix *below;
    int line;
    int column;
    float info;
};

typedef struct matrix Matrix;

Matrix* matrix_create (void);
void    matrix_destroy (Matrix* m);
void    matrix_print (Matrix* m);
Matrix* matrix_add (Matrix *m, Matrix *n);
Matrix* matrix_multiply (Matrix *m, Matrix *n);
Matrix* matrix_transpose (Matrix *m, Matrix *n);
float   getElem(Matrix* m, int line, int column);
void    setElem(Matrix* m, int line, int column, float content);
//ExtraFunctions
void    adjustPointer(Matrix* m, Matrix* newNode);
Matrix* startMatrixPointers(int lines, int columns);
int     getLines(Matrix *m);
int     getColumns(Matrix *m);
Matrix* matrix100Megas(unsigned int m);

#endif