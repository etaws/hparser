include ../../BuildDefs

OBJS_PATH       := $(PREFIX)/obj

LOCAL_PATH      := .
INCLUDES_PATH   := $(PREFIX)/src
SRCS_PATH       := $(PREFIX)/src

EXE             := token_test

TOKEN_SRCS        := hps_token.c
TOKEN_OBJS        := $(patsubst %.c,$(OBJS_PATH)/%.o,$(TOKEN_SRCS))
TOKEN_DEPS        := $(patsubst %.c,$(OBJS_PATH)/%.d,$(TOKEN_SRCS))

.PHONY: clean

all: $(EXE)

token_test: token_test.o $(TOKEN_OBJS)
	$(LINK) $^ -o $@

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c 
	@if test ! -d $(OBJS_PATH); then \
		/bin/mkdir -p $(OBJS_PATH); \
	fi; 
	$(call make-depend,$<,$@,$(subst .o,.d,$@))
	$(CC) $(CFLAGS) -I$(INCLUDES_PATH) -c $< -o $@

%.o: %.c
	$(call make-depend,$<,$@,$(subst .o,.d,$@))
	$(CC) $(CFLAGS) -I$(INCLUDES_PATH) -c $< -o $@

-include $(TOKEN_DEPS)

clean:
	@$(RM) -rf *.d $(TOKEN_DEPS) $(TOKEN_OBJS) *.o $(EXE) *.log

define make-depend
        $(CC) -MM            \
         -MF $3         \
         -MP            \
         -MT $2         \
         $(CFLAGS)      \
         -I$(INCLUDES_PATH)      \
         $1
endef
