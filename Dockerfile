# docker pull debian:latest
FROM debian:latest
RUN apt-get --assume-yes update
RUN apt-get --assume-yes upgrade
RUN apt-get --assume-yes install python3-dev git pkg-config vim wget build-essential

RUN groupadd -r developer && useradd -d /home/developer -m -s /bin/bash -g developer developer

# at this moment, debian repo has 1.3 (not the required 1.5)
WORKDIR /tmp
RUN wget https://storage.googleapis.com/golang/go1.5.1.linux-amd64.tar.gz 
RUN tar -C /usr/local -xzf go1.5.1.linux-amd64.tar.gz

USER developer
WORKDIR /home/developer
ENV HOME /home/developer
ENV GOROOT /usr/local/go
ENV PATH $PATH:$GOROOT/bin

RUN git clone https://github.com/sanderjo/python-modules-with-go.git
WORKDIR /home/developer/python-modules-with-go
RUN go build -buildmode=c-shared -o foo.so
RUN python3 -c 'import foo; print(foo.sumof3(2,40,30))'
