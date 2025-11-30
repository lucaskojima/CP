#!/bin/bash
if [ -z "$1" ]; then
	echo "Usage: $0 <problem_name>"
	exit 1
fi

PROB_NAME="$1"
TEMPLATE="template"

mkdir "$PROB_NAME" || { exit 1; }

if [ -d "$TEMPLATE" ] && [ "$(ls -A "$TEMPLATE")" ]; then
	cp -r "$TEMPLATE"/* "$PROB_NAME"
fi

echo "Generated problem '$PROB_NAME'"
