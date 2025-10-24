FROM ubuntu:22.04

ARG USERNAME=exercism
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Install language
RUN apt-get update && apt-get install -y \
  locales \
  && locale-gen en_US.UTF-8 \
  && update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8 \
  && rm -rf /var/lib/apt/lists/*
ENV LANG en_US.UTF-8

# Create a non-root user
RUN groupadd --gid $USER_GID $USERNAME \
  && useradd -s /bin/bash --uid $USER_UID --gid $USER_GID -m $USERNAME \
  # Add sudo support for the non-root user
  && apt-get update \
  && apt-get install -y sudo \
  && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME\
  && chmod 0440 /etc/sudoers.d/$USERNAME \
  && rm -rf /var/lib/apt/lists/*

# Use default bashrc for user
RUN cp /etc/skel/.bashrc /home/$USERNAME

# Set up autocompletion for user
RUN apt-get update && apt-get install -y git-core bash-completion \
  && echo "if [ -f /opt/ros/${ROS_DISTRO}/setup.bash ]; then source /opt/ros/${ROS_DISTRO}/setup.bash; fi" >> /home/$USERNAME/.bashrc \
  && echo "if [ -f /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash ]; then source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash; fi" >> /home/$USERNAME/.bashrc \
  && rm -rf /var/lib/apt/lists/* 

# Give new user rights to its own home dir
RUN chown $USER_UID:$USER_GID /home/$USERNAME

# Install exercism CLI
RUN apt-get update && apt-get install -y curl bats && \
    curl -L https://github.com/exercism/cli/releases/download/v3.0.13/exercism-3.0.13-linux-x86_64.tar.gz --output exercism-3.0.13-linux-x86_64.tar.gz && \
    mkdir exercism-3.0.13-linux-x86_64 && \
    tar xfz exercism-3.0.13-linux-x86_64.tar.gz -C ./exercism-3.0.13-linux-x86_64 && \
    cp exercism-3.0.13-linux-x86_64/exercism /usr/local/bin/ && \
    mkdir /app && \
    chown exercism /app && \
    apt-get clean

WORKDIR /app
USER exercism
