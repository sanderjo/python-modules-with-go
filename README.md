# python-modules-with-go
python modules with go

Based on https://blog.filippo.io/building-python-modules-with-go-1-5/#thecompletedemosource


## Building:
```
$ go build -buildmode=c-shared -o foo.so
# _/home/sander/golang/mijn-module/example-final
./foo.c:20:5: warning: initialization from incompatible pointer type [enabled by default]
     {"sumof3", sumof3, METH_VARARGS, "Add three numbers."},
     ^
./foo.c:20:5: warning: (near initialization for ‘FooMethods[1].ml_meth’) [enabled by default]
```
To do: get rid of that warning ...

## Resulting files:
```
-rw-rw-r-- 1 sander sander     966 nov 26 08:00 foo.c
-rw-r--r-- 1 sander sander    1679 nov 26 08:06 foo.h
-rw-r--r-- 1 sander sander 1588760 nov 26 08:06 foo.so
-rw-rw-r-- 1 sander sander     902 nov 26 08:00 sum.go
```


## Usage:
```
$ python3 -c 'import foo; print(foo.sumof3(2,40,30) )'
72
```
