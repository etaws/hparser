include ../../BuildDefs

OBJS_PATH       := $(PREFIX)/obj

LOCAL_PATH      := .
INCLUDES_PATH   := $(PREFIX)/src
SRCS_PATH       := $(PREFIX)/src

EXE             := log_test

LOG_SRCS        := hps_log.c
LOG_OBJS        := $(patsubst %.c,$(OBJS_PATH)/%.o,$(LOG_SRCS))
LOG_DEPS        := $(patsubst %.c,$(OBJS_PATH)/%.d,$(LOG_SRCS))

.PHONY: clean

all: $(EXE)

log_test: log_test.o $(LOG_OBJS)
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

-include $(LOG_DEPS)

clean:
	@$(RM) -rf *.d $(LOG_DEPS) $(LOG_OBJS) *.o $(EXE) *.log

define make-depend
        $(CC) -MM            \
         -MF $3         \
         -MP            \
         -MT $2         \
         $(CFLAGS)      \
         -I$(INCLUDES_PATH)      \
         $1
endef
