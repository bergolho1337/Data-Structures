#!/bin/bash
PNAME="./bin/Matrix"

if [ ! -f $PNAME ]; then
	./recompile_project.sh
fi

valgrind --leak-check=full --show-leak-kinds=all $PNAME
