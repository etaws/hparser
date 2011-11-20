include ../../BuildDefs

OBJS_PATH       := $(PREFIX)/obj

LOCAL_PATH      := .
INCLUDES_PATH   := $(PREFIX)/src
SRCS_PATH       := $(PREFIX)/src

EXE             := file_test ut_file_test

FILE_SRCS		:= file.c
FILE_OBJS		:= $(patsubst %.c,$(OBJS_PATH)/%.o,$(FILE_SRCS))
FILE_DEPS		:= $(patsubst %.c,$(OBJS_PATH)/%.d,$(FILE_SRCS))

.PHONY: clean

all: $(EXE)

file_test: file_test.o $(FILE_OBJS)
	$(LINK) $^ -o $@

ut_file_test: ut_file_test.o $(FILE_OBJS)
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

-include $(FILE_DEPS)

clean:
	@$(RM) -rf *.d $(FILE_DEPS) $(FILE_OBJS) *.o $(EXE)

define make-depend
        $(CC) -MM            \
         -MF $3         \
         -MP            \
         -MT $2         \
         $(CFLAGS)      \
         -I$(INCLUDES_PATH)      \
         $1
endef
