#ifndef MAIN_H
#define MAIN_H

struct matrix{
    struct matrix *left;
    struct matrix *below;
    int line;
    int column;
    float info;
};

typedef struct matrix Matrix;

Matrix* matrix_create (void);
Matrix* insertHeadLines (Matrix* head, int value);
Matrix* insertHeadColumns (Matrix* head, int value);
void matrix_destroy (Matrix* m);
void matrix_print (Matrix* m);
Matrix* matrix_add (Matrix *m, Matrix *n);
Matrix* matrix_multiply (Matrix *m, Matrix *n);
Matrix* matrix_transpose (Matrix *m, Matrix *n);
Matrix* getelem(Matrix* m, int line, int column);
Matrix* setelem(Matrix* m, int line, int column, float content);

#endif