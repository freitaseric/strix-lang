PROJECT_NAME=strix

SOURCE_PATH=src
INCLUDE_PATH=include
BINARY_PATH=bin

CC=clang
C_FLAGS=-std=c99 -Wall
C_MAIN=${SOURCE_PATH}/${PROJECT_NAME}.c
C_OUT=${BINARY_PATH}/${PROJECT_NAME}

.PHONY: ${C_OUT}, all, run, clean

all: ${C_OUT}

${C_OUT}: ${C_MAIN}
	mkdir -p ${BINARY_PATH}
	${CC} ${C_FLAGS} ${C_MAIN} -o ${C_OUT}
	chmod +x ${C_OUT}

run: ${C_OUT}
	${C_OUT}

clean: ${C_OUT}
	rm -rf ${BINARY_PATH}