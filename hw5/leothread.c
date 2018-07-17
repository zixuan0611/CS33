#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct lianxiao{
    int label;
    int count;
};

int leonardonum(int count);
void *thread(void *vargp);

int main(int argc, const char * argv[]) {
    int count = atoi(argv[1]);
    struct lianxiao argument;
    if (count < 0)
    {
        printf("N must be a positive command-line argument. \n");
        exit(1);
    }
    else
    {
        argument.label = 0;
        argument.count = count;
        pthread_t tid;
        pthread_create(&tid, NULL, thread, (void *)&argument);
        pthread_join(tid, NULL);
        exit(0);
    }
}

int leonardonum(int count)
{
    if (count == 0 || count == 1)
        return 1;
    else if (count > 1)
        return leonardonum(count - 1) + leonardonum(count - 2) + 1;
    else
        return 0;
}

void *thread(void *vargp)
{
    struct lianxiao *current;
    current = (struct lianxiao *)vargp;
    int curcount = (*current).count;
    int curlabel = (*current).label;
    pthread_t tid[2];
    
    if (curcount > 1)
    {
        struct lianxiao argument_1, argument_2;
        argument_1.label = curlabel + 1;
        argument_1.count = curcount - 1;
        argument_2.label = curlabel + leonardonum(curcount - 1) + 1;
        argument_2.count = curcount - 2;
        
        printf("(%d\n", curlabel);
        pthread_create(&tid[0], NULL, thread, (void *)&argument_1);
        pthread_join(tid[0], NULL);
        pthread_create(&tid[1], NULL, thread, (void *)&argument_2);
        pthread_join(tid[1], NULL);
        printf("%d)\n", curlabel);
    }
    else
        printf("[%d]\n", curlabel);
    
    return NULL;
}

