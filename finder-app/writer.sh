#!/bin/bash

set -e


if [[ -z "$1" || -z "$2" ]]
then
    echo "Missing parameters"
    exit 1
else
   writefile=$1
   writestr=$2
   
   mkdir -p "$(dirname $writefile)" && touch "$writefile"
   echo "$writestr" > $writefile
fi
