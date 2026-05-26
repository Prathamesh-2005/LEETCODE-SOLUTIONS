typedef struct {
    pthread_mutex_t lock;
    sem_t ready;
    int turn;
} Foo;

void printFirst();
void printSecond();
void printThird();

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    pthread_mutex_init(&obj->lock,NULL);
    sem_init(&obj->ready,0,0);
    obj->turn=1;
    return obj;
}

void first(Foo* obj) {
    pthread_mutex_lock(&obj->lock);
    printFirst();
    obj->turn=2;
    pthread_mutex_unlock(&obj->lock);
    sem_post(&obj->ready);
}

void second(Foo* obj) {
    while(1)
    {
        sem_wait(&obj->ready);
        pthread_mutex_lock(&obj->lock);

        if(obj->turn==2)
        {
            pthread_mutex_unlock(&obj->lock);
            break;
        }
        pthread_mutex_unlock(&obj->lock);
        sem_post(&obj->ready);
    }
    printSecond();

    pthread_mutex_lock(&obj->lock);
    obj->turn=3;
    pthread_mutex_unlock(&obj->lock);

    sem_post(&obj->ready);
}

void third(Foo* obj) {
    while(1)
    {
        sem_wait(&obj->ready);

        pthread_mutex_lock(&obj->lock);
        if(obj->turn==3)
        {
            pthread_mutex_unlock(&obj->lock);
            break;
        }
        pthread_mutex_unlock(&obj->lock);
        sem_post(&obj->ready);
    }
    printThird();
}

void fooFree(Foo* obj) {
    pthread_mutex_destroy(&obj->lock);
    sem_destroy(&obj->ready);
    free(obj);
}