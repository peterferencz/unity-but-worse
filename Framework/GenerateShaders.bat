#!/bin/bash

INPUT_DIR="resources/shaders"
# Directory where the generated headers will go
OUTPUT_DIR="lib/__generated/shaders"

mkdir -p "$OUTPUT_DIR"

for file in "$INPUT_DIR"/*.glsl; do
    filename=$(basename -- "$file")
    filename_no_ext="${filename%.*}"
    
    # We use sed to ensure the variable name is clean (e.g., my_shader_glsl)
    xxd -i "$file" > "$OUTPUT_DIR/$filename_no_ext.h"
    
    echo "Generated $OUTPUT_DIR/$filename_no_ext.h"
done