#define NULL 0
#define ALLOCSIZE 10000 

static char allocbuf[ALLOCSIZE];
static struct header *freelist = NULL;

struct header {
    struct header *next; 
    unsigned size;
};

char* calloc(n,size)
unsigned size;
unsigned n;
{
    unsigned length = n * size;
    char *p, *start;
    unsigned i;
    start = alloc(length);
    p = start;
    for (i = 0; i < length; i++){
        *p++ = 0;
    }
    return start;
}

char* newalloc(n)
unsigned n;
{
    if (n > 100 || n == 0) {
        return NULL;
    }
    char *p;
    p = alloc(n);
    if (p == NULL) {
        return NULL;
    }
    return p;
}



free_safe(p)
char *p;
{
    struct header *bp;
    
    if (p == NULL)
        return;
    
    if (p < allocbuf || p >= allocbuf + ALLOCSIZE)
        return;
    
    bp = (struct header *)p - 1;
    
    if (bp->size == 0 || bp->size > ALLOCSIZE)
        return;
}

bfree(p, n)
char *p;
unsigned n;
{
    struct header *bp;
    
    if (p == NULL)
        return;
    
    if (n < sizeof(struct header))
        return;
    
    bp = (struct header *)p;
    
    bp->size = n / sizeof(struct header);
    
    free((char *)(bp + 1));
}