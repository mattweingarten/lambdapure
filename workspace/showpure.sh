#! /bin/bash



FNAME="${1%%.*}"

$(~/../../mnt/c/Users/Matthew/Desktop/lean4/bin/lean $1 2> ./$FNAME.show)
# set_option trace.compiler.lambda_pure true
