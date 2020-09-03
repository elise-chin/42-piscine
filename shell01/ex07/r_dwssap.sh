#!/bin/sh
cat /etc/passwd | grep -v '^#' | cut -d : -f 1-4,6-7 | sed -n "n;p;" | cut -d : -f 1 | rev | sort -r | awk "NR>=$FT_LINE1 && NR<=$FT_LINE2" | tr '\n' ' ' | sed "s/ /, /g" | sed -E 's/, ([^, ]*)$/.\1/' | tr -d "\n"
