#!/bin/sh
# export DYLD_LIBRARY_PATH=$HOME"/42/libft_malloc/"
export DYLD_INSERT_LIBRARIES=$HOME"/42/libft_malloc/libft_malloc.so"
export DYLD_FORCE_FLAT_NAMESPACE=1
$@
