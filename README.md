# python-modules-with-go
python modules with go

Based on https://blog.filippo.io/building-python-modules-with-go-1-5/#thecompletedemosource

## Needed:
* golang (version 1.5 or higher)
* python3
* python3-dev
* pkg-config

Easy way to install most recent Go on Ubuntu:
```
sudo add-apt-repository  ppa:ubuntu-lxc/lxd-stable
```
... and then the ususal update/upgrade/install commands


## Building:
```
$ go build -buildmode=c-shared -o foo.so
```

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
