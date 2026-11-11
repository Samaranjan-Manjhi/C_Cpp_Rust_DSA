#!/bin/bash

DIR="$1"
OUTPUT="$(dirname "$0")/../home_work.txt"

if [ -z "$DIR" ]; then
    echo "Usage: $0 <directory_path>"
    exit 1
fi

mkdir -p "$(dirname "$OUTPUT")"

missing_files=()

while IFS= read -r cpp_file
do
    dir=$(dirname "$cpp_file")
    filename=$(basename "$cpp_file" .cpp)
    binary="$dir/$filename"

    # Check if executable binary exists in the same directory
    if [ ! -f "$binary" ] || [ ! -x "$binary" ]; then
        missing_files+=("$cpp_file")
    fi

done < <(find "$DIR" -type f -name "*.cpp")

{
    echo "[$(date '+%Y-%m-%d %H:%M:%S')]"

    #count=1
    #for file in "${missing_files[@]}"
    #do
    #    echo "${count}] $file"
    #    ((count++))
    #done

    count=1
    for file in "${missing_files[@]}"
    do
        printf "%02d] %s\n" "$count" "$file"
        ((count++))
    done

    echo
} >> "$OUTPUT"

echo "Report appended to: $OUTPUT"
echo "Missing binaries: $((${#missing_files[@]}))"
