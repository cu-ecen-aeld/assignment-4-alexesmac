#!/bin/sh

set -e


if [[ -z "$1" || -z "$2" ]]
then
    echo "Missing parameters"
    exit 1
else
   FILESDIR=$1
   SEARCHSTR=$2

   if [ -d "$FILESDIR" ]
   then
      cd $FILESDIR 
      numOfFiles=$(find . -type f | wc -l)
      numOfMatches=$(find . -type f -exec grep "$SEARCHSTR" {} \; | wc -l)
      echo "The number of files are $numOfFiles and the number of matching lines are $numOfMatches"
   else
      echo "Not a directory"
    fi
fi
