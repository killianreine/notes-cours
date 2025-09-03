#!/bin/bash
for file in *.scss; do
    [ -e "$file" ] || continue
    sass "$file" "${file%.scss}.css"
    echo "✅ $file → ${file%.scss}.css"
done
