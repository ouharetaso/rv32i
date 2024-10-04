CC			= gcc-14
CXX			= g++-14
CFLAGS		= -Wall -g -O0
CXXFLAGS	=
CPPFLAGS	= 
LDFLAGS 	=  
LIBS		= 

TARGET		= $(notdir $(shell pwd))
SRCDIR		= src obj_dir
OBJDIR		= build
INCDIR		= include obj_dir /opt/homebrew/opt/verilator/share/verilator/include

SUFFIXES	= .c .cpp .s

SRCS		= $(foreach src, $(SRCDIR), $(foreach suffix, $(SUFFIXES), $(wildcard $(src)/*$(suffix))))
VERILOG_SRCS= $(wildcard $(SRCDIR)/*.v)
OBJS		= $(addsuffix .o,$(addprefix $(OBJDIR)/, $(notdir $(basename $(SRCS) ) ) ) )

INCOPT		= $(addprefix -I,$(INCDIR) )

#$(warning $(SRCS))

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LIBS)



define c_rule
$(OBJDIR)/%.o: $(1)/%.c
	@mkdir -p $(OBJDIR)
	$(warning $@)
	$(CC) $(CFLAGS) $(INCOPT) -c $$< -o $$@
endef

define cpp_rule
$(OBJDIR)/%.o: $(1)/%.cpp
	@mkdir -p $(OBJDIR)
	$(warning $@)
	$(CC) $(INCOPT) $(CFLAGS) -c $$< -o $$@
endef

$(foreach dir, $(SRCDIR), $(eval $(call c_rule,$(dir))))
$(foreach dir, $(SRCDIR), $(eval $(call cpp_rule,$(dir))))

clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean