        integer i, n
        real x
        double precision xx

        open (1, FILE="QNG")

C       loop 1- set mode to normal distribution, get 6 values
        print *,"Normal distribution"
        write (1, *) "M88"
        do 200 n=1,6
        read (1,*) x
        print *,n, x
200     continue

C       loop 2- set mode to uniform distribution, get 6 values
        print *,"Uniform distribution, high precision"
        write (1, *) "M0C"
        do 400 n=1,6
        read (1,*) xx
        print *,n, xx
400     continue

C       loop 3- set mode to uniform binary, get 6 values
        print *,"Uniform binary integers"
        write (1, *) "M10"
        do 600 n=1,6
        read (1,*) i
        print *,n, i
600     continue

        close (1)
        stop
        end

