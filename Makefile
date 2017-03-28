# function to remove files in $(1) list
RM=@for i in $(1);do \
	if test -e $$i;then rm $$i; echo "[removing]"$$i; fi;\
done
# function to delete the outdated dependance files.
RMDEP=@for i in $(DEP_DIR)/*.d	;do \
	if ! test -e $(SRC_DIR)/`basename $$i .d`.c;then rm $$i;fi;\
done

# names
SRC_DIR=./src
OBJ_DIR=./obj
BIN_DIR=./bin
DEP_DIR=./dep
SRC=$(wildcard $(SRC_DIR)/*.c)
OBJ=$(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))
DEP=$(addprefix $(DEP_DIR)/,$(notdir $(SRC:.c=.d)))
BIN=$(BIN_DIR)/ds

CFLAGS=-Wall -g -std=c11
CC=gcc

.PHONY:all clean remove help backup

all:$(BIN) $(DEP)

-include $(DEP)

$(BIN):$(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ) -lm

$(OBJ):$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(DEP):$(DEP_DIR)/%.d:$(SRC_DIR)/%.c
	$(call RM,$@)
	$(CC) -MM $< | sed 's,\($*\)\.o[ :]*,$(OBJ_DIR)/\1.o $@ : ,g' > $@


help:
	@echo -e \
"Usage:\n\
(all)	:	build the whole project.\n\
clean	:	remove the object files.\n\
remove	:	remove the binary file.\n\
backup	:	tar the source file into a tar file named src.tar.gz"

remove:
	$(call RM,$(wildcard $(BIN_DIR)/*))

clean:
	$(call RM,$(wildcard $(OBJ_DIR)/* $(DEP_DIR)/*))

test:
