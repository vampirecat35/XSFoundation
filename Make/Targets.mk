#-------------------------------------------------------------------------------
# The MIT License (MIT)
# 
# Copyright (c) 2020 Jean-David Gadina - www.xs-labs.com
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Built-in targets
#-------------------------------------------------------------------------------

# Default make target
.DEFAULT_GOAL := all

# Declaration for phony targets, to avoid problems with local files
.PHONY: all clean clean_temp clean_products doc debug release lib example example_debug example_release example_exec

# Declaration for precious targets, to avoid cleaning of intermediate files
.PRECIOUS: $(DIR_BUILD_TEMP)%$(EXT_O)

#-------------------------------------------------------------------------------
# Phony targets
#-------------------------------------------------------------------------------

# Main Target
all: debug release
	
	@:

# Example Target
example: example_debug example_release
	
	@:

# Cleans all build files
clean:
	
	@$(MAKE) -s clean_temp DEBUG=1
	@$(MAKE) -s clean_products DEBUG=1
	@$(MAKE) -s clean_temp
	@$(MAKE) -s clean_products
	
# Clean temporary files
clean_temp:
	
	$(call PRINT_ARCH,$(_HOST_ARCH),Cleaning all intermediate files)
	@rm -rf $(DIR_BUILD_TEMP)*
	
# Clean products
clean_products:
	
	$(call PRINT_ARCH,$(_HOST_ARCH),Cleaning all product files)
	@rm -rf $(DIR_BUILD_PRODUCTS)*
	
# Documentation
doc:
	
ifeq ($(_HAS_XSDOCGEN),true)
	$(call PRINT,XSDoc,Generating the documentation)
	@/usr/local/bin/XSDocgen \
	@    --clear \
	@    --source XSFoundation/include \
	@    --output Documentation \
	@    --exclude-file HeaderDoc-Exclude.txt \
	@    --project-name "XSFoundation" \
	@    --project-copyright "XS-Labs &copy; %Y - All Rights Reserved" \
	@    --project-version "2.0.0-0" \
	@    --project-timezone "Europe/Zurich" \
	@    --company-name "XS-Labs" \
	@    --company-url "http://www.xs-labs.com/" \
	@    --page-home "Pages/Home.inc.php" \
	@    --source-root-prefix "/XSFoundation/include/" \
	@    --classes-prefix "XSFoundation/include/XS/Classes/" \
	@    --functions-prefix "XSFoundation/include/XS/Functions/" \
	@    --types-prefix "XSFoundation/include/XS/XSTypes/" \
	@    --page-add "Building XSFoundation" "Pages/Build.inc.php" \
	@    --page-add "Memory management" "Pages/Memory.inc.php" \
	@    --page-add "Class definition" "Pages/Classes.inc.php" \
	@    --google-analytics "UA-51035898-4" "xs-labs.com" \
	@    --google-analytics-display-features
else
	$(call PRINT,XSDoc,Skipping documentation generation - XSDocgen is not installed)
endif

# Debug build (parallel if available)
debug:
	
ifeq ($(_MAKE_4),true)
	@$(MAKE) -s -j 50 --output-sync lib DEBUG=1
else
	@$(MAKE) lib DEBUG=1
endif
	
# Release build (parallel if available)
release:
	
ifeq ($(_MAKE_4),true)
	@$(MAKE) -s -j 50 --output-sync lib
else
	@$(MAKE) lib
endif

# Example debug build (parallel if available)
example_debug:
	
ifeq ($(_MAKE_4),true)
	@$(MAKE) -s -j 50 --output-sync example_exec DEBUG=1
else
	@$(MAKE) example_exec DEBUG=1
endif
	
# Example release build (parallel if available)
example_release:
	
ifeq ($(_MAKE_4),true)
	@$(MAKE) -s -j 50 --output-sync example_exec
else
	@$(MAKE) example_exec
endif
	
# Example executable
example_exec: lib

	$(call PRINT_ARCH,$(_HOST_ARCH),"Compiling and linking example")
	@$(_CC) -lxs -L$(DIR_BUILD_PRODUCTS) -o $(DIR_BUILD_PRODUCTS)example $(abspath example/main.c)

#-------------------------------------------------------------------------------
# Targets with second expansion
#-------------------------------------------------------------------------------

.SECONDEXPANSION:

# Static library
lib: _OBJ = $(DIR_BUILD_TEMP)XSFoundation$(EXT_O)
lib: _LIB = $(DIR_BUILD_PRODUCTS)$(PRODUCT)$(EXT_LIB)
lib: $$(_FILES_C_BUILD)

	$(call PRINT_ARCH,$(_HOST_ARCH),"Linking object files"): $(COLOR_BLUE)$(notdir $(_OBJ))$(COLOR_NONE)
	@rm -f $(_OBJ)
	@ld -r $(_FILES_C_BUILD) -o $(_OBJ)
	
	$(call PRINT_ARCH,$(_HOST_ARCH),"Creating static library"): $(COLOR_BLUE)$(notdir $(_LIB))$(COLOR_NONE)
	@libtool -static -o $(_LIB) $(_OBJ)
	
ifeq ($(findstring 1,$(DEBUG)),)
	$(call PRINT_ARCH,$(_HOST_ARCH),"Stripping debug symbols"): $(COLOR_BLUE)$(notdir $(_LIB))$(COLOR_NONE)
	@strip -S $(_LIB)
endif

# Target: Object file
$(DIR_BUILD_TEMP)%$(EXT_O): $$(shell mkdir -p $$(dir $$@)) %$(EXT_C)
	
	$(call PRINT_FILE,$(_HOST_ARCH),"Compiling C file",$<)
	@$(_CC) -o $@ -c $(abspath $<)
