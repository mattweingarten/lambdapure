#! /bin/bash


COMPILING=$(grep -c 'set_option trace.compiler.ir.init true' $1)
if [ $COMPILING -eq 0 ]
then
  $(echo 'set_option trace.compiler.ir.init true' | cat - $1 > temp && mv temp $1)
fi
FNAME="${1%%.*}"

$(~/../../mnt/c/Users/Matthew/Desktop/lean4/bin/lean $1 2> ./$FNAME.lambdapure)

sed 's/\[\init\]//g' ./$FNAME.lambdapure |& tee tmp && mv tmp ./$FNAME.lambdapure
sed 's/\set_option trace.compiler.ir.init true//g' ./$FNAME.lambdapure |& tee tmp && mv tmp ./$FNAME.lambdapure
echo ""
