FROM ubuntu:latest

ARG DEBIAN_FRONTEND=noninteractive

#install basic tools dependencies and utilities
RUN apt update && apt install -y curl nano
RUN apt install build-essential -y
RUN apt install -y python3 python3-pip
RUN apt install -y git
RUN apt install -y cmake

#for some reason the following packages are not available in the ubuntu repository
#RUN apt install -y freeglut3 
#RUN apt install -y libvorbis-dbg
RUN apt install -y freeglut3-dev libplib-dev libopenal1 libopenal-dev libopenal-data libalut0 libalut-dev libvorbis-dev libxi6 libxi-dev libxmu6 libxmu-headers libxmu-dev 
RUN apt install  -y libxrender1 libxrender-dev libxrandr2 libxrandr-dev libpng16-16 libpng-dev
RUN apt install libxxf86vm-dev

WORKDIR /usr/local/src

ADD torcs-1.3.7.pre_compiled.tar /usr/local/src

#copy scrips in the container
COPY scripts/full_compile.bash /usr/local/src/full_compile.bash

ENV WORK_BASE=/usr/local/src
ENV TORCS_BASE=/usr/local/src/torcs-1.3.7
ENV MAKE_DEFAULT=$TORCS_BASE/Make-default.mk
ENV LD_LIBRARY_PATH=/usr/local/lib

#not needed since the container is run as root
#RUN chown -R $USER torcs-1.3.7

CMD ["/bin/bash"]
