cat /etc/passwd | grep -v "^#" | sed '1!n;d' | cut -d":" -f 1 | rev | sort -r | awk 'NR >= ENVIRON["FT_LINE1"] && NR <= ENVIRON["FT_LINE2"]' | xargs | sed 's/ /, /g' | sed 's/$/./' | tr -d '\n'
