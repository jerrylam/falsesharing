FROM ubuntu:14.04
MAINTAINER Jerry Lam "jerry.lam@paytm.com"

RUN apt-get update -qqy && \
    apt-get update -y && \
    apt-get install -y   \
      gcc-4.7 \
      g++-4.7 \
      gdb \
      build-essential \
      git-core \
      ruby \
      ruby-dev \
      bundler && \
    apt-get clean

RUN git clone https://github.com/jerrypaytm/falsesharing.git && cd /falsesharing && git checkout
RUN cd /falsesharing/falsesharing/falsesharing && g++ -std=c++0x -pthread main.cpp
ENTRYPOINT ["/falsesharing/falsesharing/falsesharing/a.out"]
