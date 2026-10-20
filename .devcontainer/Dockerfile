FROM debian:bookworm

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    gcc-arm-none-eabi \
    binutils-arm-none-eabi \
    libnewlib-arm-none-eabi \
    libusb-1.0-0-dev \
    gdb-multiarch \
    cmake \
    ninja-build \
    git \
    python3 \
    python3-pip \
    clangd \
    clang-format \
    cppcheck \
    doxygen \
    graphviz \
    openocd \
    usbutils \
    pkg-config \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

ENV PATH="/root/.mcu-debug/bin:${PATH}"

# Pico SDK
ARG PICO_SDK_VERSION=2.2.0

RUN git clone --depth 1 \
    --branch ${PICO_SDK_VERSION} \
    https://github.com/raspberrypi/pico-sdk.git \
    /opt/pico-sdk

ENV PICO_SDK_PATH=/opt/pico-sdk

RUN cd ${PICO_SDK_PATH} && git submodule update --init --recursive

RUN git clone --depth 1 --branch ${PICO_SDK_VERSION} https://github.com/raspberrypi/picotool.git /tmp/picotool \
    && cmake -S /tmp/picotool -B /tmp/picotool/build -DPICO_SDK_PATH=/opt/pico-sdk \
    && cmake --build /tmp/picotool/build --parallel \
    && cmake --install /tmp/picotool/build \
    && rm -rf /tmp/picotool

# Przydatne narzędzia Pico
RUN python3 -m pip install --break-system-packages \
    pyserial

ENV PATH="/opt/pico-sdk/tools:${PATH}"

WORKDIR /workspace

RUN ln -s /workspace/firmware/board/pol_deck.h ${PICO_SDK_PATH}/src/boards/include/boards/pol_deck.h

# Pico TFT
RUN git clone --depth 1 \
    https://github.com/xKraZx/ili9488-pico.git \
    /opt/pico-ili9488

ENV PICO_ILI9488=/opt/pico-ili9488
