class Foo {
    int status=1;
    public Foo() {
        
    }

    public synchronized void first(Runnable printFirst) throws InterruptedException {
        while(status!=1)
        {
            wait();
        }
        if(status==1)
        printFirst.run();
        status=2;
        notifyAll();
    }

    public synchronized void second(Runnable printSecond) throws InterruptedException {
        while(status!=2)
        {
            wait();
        }

        if(status==2)
        printSecond.run();
        status=3;
        notifyAll();
    }

    public synchronized void third(Runnable printThird) throws InterruptedException {
        while(status!=3)
        {
            wait();
        }
        if(status==3)
        printThird.run();
        status=1;
        notifyAll();
    }
}