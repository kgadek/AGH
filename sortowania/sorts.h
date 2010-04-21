int check(int *, int);
void swap(int *, int *);
void combsort_kg(int *, int);
void inssort_mk(int *, int);
void selsort_mk(int *, int);
void bubblesort_mk(int *, int);
void quicksort_h_kg(int *, int);
void quicksort_h_kg_int(int *, int, int);
void quicksort_h_kg_part(int *, int, int, int*, int*);
void quicksort_h_mk(int *, int);
void quicksort_h_mk_int(int *, int, int);
void shlsort_mk(int *, int);
void mergesort_mk(int *, int);
void mergesort_mk_int(int *, int, int);

struct stck{
    struct stck* n;
    int v;
};

extern struct stck* R;

void Sinit(void);
void Spush(int);
void Spop(void);
int Sfront(void);
int Sempty(void);
void Sclear(void);

