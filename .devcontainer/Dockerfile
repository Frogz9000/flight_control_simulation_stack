# Download base image ubuntu 20.04
FROM ubuntu:20.04

# Disable Prompt During Packages Installation
ARG DEBIAN_FRONTEND=noninteractive

# Update Ubuntu Software repository
RUN apt-get update && apt-get install -y \
    make \
    cmake \
    g++ \
    libncurses5-dev \
    libncursesw5-dev \
    git \
    clang-tools-8 \
&& rm -rf /var/lib/apt/lists/*

# RUN update-alternatives --install /usr/bin/clangd clangd /usr/bin/clang-8 100

CMD ["bash"]