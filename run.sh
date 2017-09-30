#!/bin/bash
if [[ `uname` == 'Darwin' ]]; then
	DYLD_LIBRARY_PATH=.  DYLD_INSERT_LIBRARIES="libft_malloc.so" DYLD_FORCE_FLAT_NAMESPACE=1 $@
else
	echo $PWD
	LD_LIBRARY_PATH=$PWD/. $@
fi
