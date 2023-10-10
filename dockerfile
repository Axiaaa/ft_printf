FROM ubuntu:jammy

RUN apt-get update && apt-get install -y \
    gcc \
    zsh \
    make \
    git \
    vim \
    && rm -rf /var/lib/apt/lists/*

RUN sh -c "$(wget https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O -)"

RUN git clone https://github.com/Axiaaa/ft_printf.git ft_printf

COPY entry_script.sh /entry_script.sh
COPY main.c /ft_printf/main.c
CMD ["/bin/zsh", "/entry_script.sh"]