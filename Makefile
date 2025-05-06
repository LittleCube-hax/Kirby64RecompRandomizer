BUILD_DIR := build

# Allow the user to specify the compiler and linker on macOS
# as Apple Clang does not support MIPS architecture
ifeq ($(OS),Windows_NT)
    CC      := C:\msys64\mingw64\bin/clang
    LD      := C:/Program Files/LLVM/bin/ld.lld
else ifneq ($(shell uname),Darwin)
    CC      := clang
    LD      := ld.lld
else
    CC      ?= clang
    LD      ?= ld.lld
endif

TARGET  := $(BUILD_DIR)/mod.elf

LDSCRIPT := mod.ld
DECOMP := k64-decomp
LIBULTRA_INC := $(DECOMP)/libreultra/include/2.0I
DECOMP_INCS := -I $(LIBULTRA_INC) -I $(LIBULTRA_INC)/PR -I $(DECOMP)/include -I $(DECOMP)/include/libc -I $(DECOMP)/src.old -I $(DECOMP)/src -I $(DECOMP)/assets


CFLAGS   := $(DECOMP_INCS) -target mips -mips2 -mabi=32 -O2 -G0 -mno-abicalls -mno-odd-spreg -mno-check-zero-division \
			-fomit-frame-pointer -ffast-math -fno-unsafe-math-optimizations -fno-builtin-memset \
			-Wall -Wextra -Wno-incompatible-library-redeclaration -Wno-unused-parameter -Wno-unknown-pragmas \
			-Wno-unused-variable -Wno-missing-braces -Wno-unsupported-floating-point-opt -Wno-visibility
CPPFLAGS := -nostdinc -Wno-incompatible-function-pointer-types -D__sgi -D_LANGUAGE_C -DTARGET_N64 -DMIPS -I include -I dummy_headers $(DECOMP_INCS)
LDFLAGS  := -nostdlib -T $(LDSCRIPT) -Map=$(BUILD_DIR)/mod.map --warn-unresolved-symbols --emit-relocs -e 0 --no-nmagic

C_SRCS := $(wildcard src/*.c)
C_OBJS := $(addprefix $(BUILD_DIR)/, $(C_SRCS:.c=.o))
C_DEPS := $(addprefix $(BUILD_DIR)/, $(C_SRCS:.c=.d))

$(TARGET): $(C_OBJS) $(LDSCRIPT) | $(BUILD_DIR)
	$(LD) $(C_OBJS) $(LDFLAGS) -o $@

$(BUILD_DIR) $(BUILD_DIR)/src $(BUILD_DIR)/output:
ifeq ($(OS),Windows_NT)
	mkdir $(subst /,\,$@)
else
	mkdir -p $@
endif

$(C_OBJS): $(BUILD_DIR)/%.o : %.c | $(BUILD_DIR) $(BUILD_DIR)/src $(BUILD_DIR)/output
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -MMD -MF $(@:.o=.d) -c -o $@

all: $(BUILD_DIR)/output/mod_binary.bin

$(BUILD_DIR)/output/mod_binary.bin: $(TARGET) mod.toml
	RecompModTool.exe mod.toml $(BUILD_DIR)/output
	@echo "Done."

clean:
	rm -rf $(BUILD_DIR)

-include $(C_DEPS)

.PHONY: clean
