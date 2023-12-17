import os
import fnmatch
import sys

def list_c_files(directory):
    for root, _, files in os.walk(directory):
        if 'libft' in root:
            continue
        for items in fnmatch.filter(files, "*.c"):
            yield items #os.path.relpath(os.path.join(root, items), directory)

if len(sys.argv) != 2:
    print("Usage: python pyscript_get_paths.py <directory>")
    sys.exit(1)

directory = sys.argv[1]
for file in list_c_files(directory):
    print(file)