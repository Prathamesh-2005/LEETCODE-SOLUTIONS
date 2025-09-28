class FizzBuzz {
    private int n;
    private int state=0;
    public FizzBuzz(int n) {
        this.n = n;
    }

    public synchronized void fizz(Runnable printFizz) throws InterruptedException {
        for(int i=1;i<=n;i++)
        {
            while(state!=0)
            {
                wait();
            }
            if(i%3==0 && i%5!=0)
            {
                printFizz.run();
            }
            state=1;
            notifyAll();
        }
    }

    public synchronized void buzz(Runnable printBuzz) throws InterruptedException {
        for(int i=1;i<=n;i++)
        {
            while(state!=1)
            {
                wait();
            }
            if(i%5==0 && i%3!=0)
            {
                printBuzz.run();
            }
            state=2;
            notifyAll();
        }
    }

    public synchronized void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for(int i=1;i<=n;i++)
        {
            while(state!=2)
            {
                wait();
            }

            if(i%3==0 && i%5==0)
            {
                printFizzBuzz.run();
            }
            state=3;
            notifyAll();
        }
    }

    public synchronized void number(IntConsumer printNumber) throws InterruptedException {
        for(int i=1;i<=n;i++)
        {
            while(state!=3)
            {
                wait();
            }

            if(i%3!=0 && i%5!=0)
            {
                printNumber.accept(i);
            }
            state=0;
            notifyAll();
        }
    }
}