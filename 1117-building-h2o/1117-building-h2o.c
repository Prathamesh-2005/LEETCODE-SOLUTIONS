typedef struct {
    int turn;
    pthread_mutex_t lock;
    pthread_cond_t cond;
} H2O;

void releaseHydrogen();

void releaseOxygen();

H2O* h2oCreate() {
    H2O* obj = (H2O*) malloc(sizeof(H2O));
    obj->turn=0;
    pthread_mutex_init(&obj->lock,NULL);
    pthread_cond_init(&obj->cond,NULL);
    return obj;
}

void hydrogen(H2O* obj) {
    pthread_mutex_lock(&obj->lock);

    while(obj->turn==2)
    {
        pthread_cond_wait(&obj->cond,&obj->lock);
    }
    releaseHydrogen();
    obj->turn++;

    pthread_cond_broadcast(&obj->cond);
    pthread_mutex_unlock(&obj->lock);
}

void oxygen(H2O* obj) {
    pthread_mutex_lock(&obj->lock);
    while(obj->turn<2)
    {
        pthread_cond_wait(&obj->cond,&obj->lock);
    }
    releaseOxygen();
    obj->turn=0;
    pthread_cond_broadcast(&obj->cond);
    pthread_mutex_unlock(&obj->lock);
}

void h2oFree(H2O* obj) {
    pthread_mutex_destroy(&obj->lock);
    pthread_cond_destroy(&obj->cond);
    free(obj);
}