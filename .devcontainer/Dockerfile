# Download base image ubuntu 20.04
FROM ubuntu:20.04

# Disable Prompt During Packages Installation
ARG DEBIAN_FRONTEND=noninteractive

# Update Ubuntu Software repository
RUN apt-get update && apt-get install -y \
    make \
    cmake \
    libncurses5-dev \
    libncursesw5-dev \
    git \
    clang \
    clangd-12 \
&& rm -rf /var/lib/apt/lists/*

#make clangd install default
RUN update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-12 100
CMD ["bash"]